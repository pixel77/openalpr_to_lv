
std::string path(char* addStr);
extern "C" void __declspec(dllexport) test_Multiple(double a, double b, double *x);
extern "C" __declspec(dllexport) char* test_Path(void);
extern "C" __declspec(dllexport) char* OALPRLabVIEW_Init(char* defReg, int topN);
extern "C" __declspec(dllexport) char* OALPRLabVIEW_Recognise(char* img);
extern "C" __declspec(dllexport) char* test_Char(void);
