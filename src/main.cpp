#include <QApplication>
#include "qtav_player.h"
#include <QMainWindow> 
#pragma comment(lib, "user32.lib")
#include "QtAVWidgets/QtAVWidgets.h"

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__) // 定义new宏来替换new关键字
#endif

int main(int argc, char *argv[])
{
    // QtAV::Widgets::registerRenderers();
    char* mem_leak = new char[1];
#ifdef _MSC_VER
    // _CrtSetBreakAlloc(590);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
#ifdef MEMORY_STDOUT // 是否将内存泄露信息，存储到文件中
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
#else
    HANDLE hLogFile;
    hLogFile = CreateFile("./memory.txt", GENERIC_WRITE,
                          FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL, NULL);
    _CrtSetReportFile(_CRT_WARN, hLogFile);
    _CrtSetReportFile(_CRT_ERROR, hLogFile);
    _CrtSetReportFile(_CRT_ASSERT, hLogFile);
#endif // MEMORY_STDOUT
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif // _MSC_VER
    QApplication a(argc, argv);
    qtav_player player;
    player.show();
    // QMainWindow aa;
    // aa.show();
    return a.exec();
}