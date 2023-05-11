#include "AppForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Создание экземпляра формы
    WinFormApp::AppForm1^ form = gcnew WinFormApp::AppForm1();

    // Запуск приложения и отображение формы
    Application::Run(form);

    return 0;
}