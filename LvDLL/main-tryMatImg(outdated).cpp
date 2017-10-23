#include <windows.h>
#include <alpr.h>
#include "extcode.h"
#include <algorithm>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\core\core.hpp>

#define THISPROG

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd // stupid MSFT "deprecation" warning
#elif
#include <unistd.h>
#endif

using namespace std;
using namespace alpr;
using namespace cv;


// Licenced by Affero GPLv3 Licence http://www.gnu.org/licenses/agpl-3.0.html


/*
string confEnd = "E:/Felhasználók/Pixelbetyár/Documents/Visual Studio 2015/Projects/LvDLL/ALPRdll/openalpr.conf";
string runtimeEnd = "E:/Felhasználók/Pixelbetyár/Documents/Visual Studio 2015/Projects/LvDLL/ALPRdll/runtime_data";
*/

string path(char* addStr) {
	/*
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	char *str = new char[MAX_PATH];
	memset(str, 0, MAX_PATH);
	wcstombs(str, buffer, MAX_PATH);

	char* asd = str;
	delete str;
	*/

	char* pPath;
	pPath = getenv("OPENALPR_PATH");
	if (pPath != NULL) {
		string lib = pPath;
		replace(lib.begin(), lib.end(), '\\', '/'); // replace all '\' to '/'

		lib = lib + addStr;

		return lib;
	}
	else {
		return "ERR";
	}

	/*
	char* cwd = getcwd(NULL, 0);
	/* cwd points to malloc'ed current working directory string */
	/* free(cwd) when you are done with it */
	/*
	string lib = cwd;
	char* asd = cwd;
	free(cwd);

	replace(lib.begin(), lib.end(), '\\', '/'); // replace all '\' to '/'

	lib = lib + addStr;

	return lib;
	*/
}

string confPub = path("/openalpr_32/openalpr.conf");
string runtimePub = path("/openalpr_32/runtime_data");

// Initialize the library using United States style license plates.
// You can use other countries/regions as well (for example: "eu", "au", or "kr")
alpr::Alpr openalpr("eu", confPub, runtimePub);

extern "C" void __declspec(dllexport) multiple(double a, double b, double *x) {
	*x = a * b;
}

extern "C" __declspec(dllexport) char* test(void) {
	
	char* pPath;
	pPath = getenv("OPENALPR_PATH");
	if (pPath != NULL) {
		return pPath;
	}
	else {
		return "ERR";
	}
	/*
	std::vector<char> writable(runtimePub.begin(), runtimePub.end());
	writable.push_back('\0');

	char* output = &writable[0];

	return output;
	*/
}

extern "C" __declspec(dllexport) char* init(char* conf, char* defReg, int32_t topN) {

	// Optionally specify the top N possible plates to return (with confidences).  Default is 10
	openalpr.setTopN(topN);

	// Optionally, provide the library with a region for pattern matching.  This improves accuracy by
	// comparing the plate text with the regional pattern.
	openalpr.setDefaultRegion("hu");

	// Make sure the library loaded before continuing.
	// For example, it could fail if the config/runtime_data is not found
	if (openalpr.isLoaded() == false)
	{
		return "ERR_LOAD";
	}
	return "OK";
}

extern "C" __declspec(dllexport) char* recognise(char* img) {

	if (openalpr.isLoaded() == false)
	{
		return "ERR_LOAD";
	}

	// Recognize an image file.  You could alternatively provide the image bytes in-memory.
	alpr::AlprResults results = openalpr.recognize(img);


	if (results.plates.size()) {
		// Iterate through the results.  There may be multiple plates in an image,
		// and each plate return sthe top N candidates.
		string allRendszam = "";
		for (int i = 0; i < results.plates.size(); i++) {
			alpr::AlprPlateResult plate = results.plates[i];

			//get the first plate number by chance
			string rendszamStr = plate.bestPlate.characters;

			//send back all the finded plates
			allRendszam = allRendszam + "Plate_" + to_string(i) + ":" + rendszamStr;
			if (i+1 < results.plates.size()) {
				allRendszam = allRendszam + ",";
			}
		}

		//string to char* and send it back
		std::vector<char> writable(allRendszam.begin(), allRendszam.end());
		writable.push_back('\0');
		
		char* output = &writable[0];
		
		return output;
	}
	else {
		//send error
		return "ERR_NO_PLATE";
	}
	

}

extern "C" _declspec(dllexport) char* sTest(void) {
	return "Teszt";
}

extern "C" __declspec(dllexport) char* recogniseV2(unsigned char *imageIN, int rows, int cols) {

	if (openalpr.isLoaded() == false)
	{
		return "ERR_LOAD";
	}

	// allocate memory
	Mat image_input(rows, cols, CV_8U, &imageIN[0]); // THIS IS THE INPUT IMAGE, POINTER TO DATA

	// Recognize an image file.  You could alternatively provide the image bytes in-memory.
	alpr::AlprResults results = openalpr.recognize(image_input);


	if (results.plates.size()) {
		// Iterate through the results.  There may be multiple plates in an image,
		// and each plate return sthe top N candidates.
		string allRendszam = "";
		for (int i = 0; i < results.plates.size(); i++) {
			alpr::AlprPlateResult plate = results.plates[i];

			//get the first plate number by chance
			string rendszamStr = plate.bestPlate.characters;

			//send back all the finded plates
			allRendszam = allRendszam + "Plate_" + to_string(i) + ":" + rendszamStr;
			if (i + 1 < results.plates.size()) {
				allRendszam = allRendszam + ",";
			}
		}

		//string to char* and send it back
		std::vector<char> writable(allRendszam.begin(), allRendszam.end());
		writable.push_back('\0');

		char* output = &writable[0];

		return output;
	}
	else {
		//send error
		return "ERR_NO_PLATE";
	}


}

extern "C" _declspec (dllexport) int CannyEdges(unsigned char *imageIN,
	int rows,
	int cols,
	double threshold1,
	double threshold2,
	int kernel_size,
	unsigned char *imageOUT)
{
	// check odd kernel size
	if (kernel_size % 2 == 0) return -1;
	// allocate memory
	Mat image_input(rows, cols, CV_8U, &imageIN[0]); // THIS IS THE INPUT IMAGE, POINTER TO DATA
	Mat image_output(rows, cols, CV_8U, &imageOUT[0]); // THIS IS THE OUTPUT IMAGE, POINTER TO DATA
													   // blur before canny
	blur(image_input, image_output, Size(3, 3));
	// canny
	Canny(image_output, image_output, threshold1, threshold2, kernel_size);


}
