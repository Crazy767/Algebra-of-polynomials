using namespace System;
using namespace System::Windows::Forms;

ref class MyForm : public Form
{
public:
    MyForm()
    {
        this->Text = "My Form";
        Button^ button = gcnew Button();
        button->Text = "click me!";
        this->Controls->Add(button);
    }
};

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyForm^ form = gcnew MyForm();

    Application::Run(form);

    return 0;
}