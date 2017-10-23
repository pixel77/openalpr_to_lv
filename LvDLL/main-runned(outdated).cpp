#include <windows.h>
#include <alpr.h>
#include "extcode.h"
#include <algorithm>
#include <string>

#define THISPROG

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd // stupid MSFT "deprecation" warning
#elif
#include <unistd.h>
#endif

using namespace std;
using namespace alpr;

string confEnd = "E:/Felhasználók\\Pixelbetyár\\Documents\\Visual Studio 2015\\Projects\\LvDLL/ALPRdll/openalpr.conf";
string runtimeEnd = "E:/Felhasználók/Pixelbetyár/Documents/Visual Studio 2015/Projects/LvDLL/ALPRdll/runtime_data";

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
	char* cwd = getcwd(NULL, 0);
	/* cwd points to malloc'ed current working directory string */
	/* free(cwd) when you are done with it */
	string lib = cwd;
	char* asd = cwd;
	free(cwd);

	replace(lib.begin(), lib.end(), '\\', '/'); // replace all '\' to '/'

	lib = lib + addStr;

	return lib;
}

string confPub = path("/ALPRdll/openalpr.conf");
string runtimePub = path("/ALPRdll/runtime_data");

// Initialize the library using United States style license plates.
// You can use other countries/regions as well (for example: "eu", "au", or "kr")
alpr::Alpr openalpr("eu", confEnd, runtimeEnd);

extern "C" void __declspec(dllexport) multiple(double a, double b, double *x) {
	*x = a * b;
}

extern "C" __declspec(dllexport) char* init(char* conf, char* runtime, int32_t topN) {

	confPub = conf;
	runtimePub = runtime;

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

	// Iterate through the results.  There may be multiple plates in an image,
	// and each plate return sthe top N candidates.


	alpr::AlprPlateResult plate = results.plates[0];
	/*
	string rendszamStr = plate.bestPlate.characters;
	char *rendszamC = new char[rendszamStr.length() + 1]; // or
	// char y[100];

	std::strcpy(rendszamC, rendszamStr.c_str());
	rendszam = rendszamC;
	*/

	string rendszamStr = plate.bestPlate.characters;
	/*
	char rendszamChar[1024];
	strncpy_s(rendszamChar, rendszamStr.c_str(), sizeof(rendszamChar));
	rendszamChar[sizeof(rendszamChar) - 1] = 0;

	rendszam = rendszamChar;

	char asd[] = "asd";
	char *abc = asd;
	*/
	std::vector<char> writable(rendszamStr.begin(), rendszamStr.end());
	writable.push_back('\0');

	char* output = &writable[0];

	return output;

}
extern "C" int32_t __declspec(dllexport) strToChar(char *cString) {
	/*
	cString = "ABCD";


	std::string str = "Teszt";
	std::vector<char> writable(str.begin(), str.end());
	writable.push_back('\0');

	cString = &writable[0];

	char* array;
	char a;
	size_t len = strlen(array);

	char* ret = new char[len + 2];

	strcpy(ret, array);
	ret[len] = a;
	ret[len + 1] = '\0';
	*/

	return 0;
}

extern "C" _declspec(dllexport) char* sTest(void) {
	return "Teszt";
}