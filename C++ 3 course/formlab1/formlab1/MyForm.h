#pragma once

namespace formlab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(486, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"calculate\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"inter array";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"answer:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(547, 302);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		array<String^>^ as;
		array<Char>^ ar;
		ar = gcnew array<Char>(1);
		ar[0] = ' ';
		Int64 ans = 1;
		Int64 min = 6546123;
		Int64 max = -21456546;
		as = textBox1->Text->Split(ar);
		for (int i = 0; i < as->Length; ++i) {
			Int64 tmp = Convert::ToInt64(as[i]);
			ans = ans*tmp;
			if (min > tmp)
				min = tmp;
			if (max < tmp)
				max = tmp;
		}
		ans = ans / max / min;
		label2->Text = "ans = " + Convert::ToString(ans);
	}
	};
}
