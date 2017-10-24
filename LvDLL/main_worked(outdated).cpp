#include <windows.h>
#include <alpr.h>
#include "extcode.h"
#include <algorithm>
#include <string>
#include "lvALPR.h"

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd // stupid MSFT "deprecation" warning
#elif
#include <unistd.h>
#endif

using namespace std;
using namespace alpr;

/*
string confEnd = "E:/Felhasználók/Pixelbetyár/Documents/Visual Studio 2015/Projects/LvDLL/ALPRdll/openalpr.conf";
string runtimeEnd = "E:/Felhasználók/Pixelbetyár/Documents/Visual Studio 2015/Projects/LvDLL/ALPRdll/runtime_data";
*/

/* 
	The OpenALPR parts are Licenced by Affero GPLv3 Licence http://www.gnu.org/licenses/agpl-3.0.html.
	For the whole licence policy check out the README.
	Created by Vágner Máté.
*/


std::string path(char* addStr) {
	/*
	w char_t buffer[MAX_PATH];
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

extern "C" void __declspec(dllexport) test_Multiple(double a, double b, double *x) {
	*x = a * b;
}

extern "C" __declspec(dllexport) char* test_Path(void) {
	
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

extern "C" __declspec(dllexport) char* OALPRLabVIEW_Init(char* defReg, int topN) {

	// Optionally specify the top N possible plates to return (with confidences).  Default is 10
	openalpr.setTopN(topN);

	// Optionally, provide the library with a region for pattern matching.  This improves accuracy by
	// comparing the plate text with the regional pattern.
	openalpr.setDefaultRegion(defReg);

	// Make sure the library loaded before continuing.
	// For example, it could fail if the config/runtime_data is not found
	if (openalpr.isLoaded() == false)
	{
		return "ERR_LOAD";
	}
	return "OK";
}

extern "C" __declspec(dllexport) char* OALPRLabVIEW_Recognise(char* img) {

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

extern "C" __declspec(dllexport) char* test_Char(void) {
	return "Teszt";
}
