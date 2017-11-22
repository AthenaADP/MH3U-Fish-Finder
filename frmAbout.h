#pragma once
#include "Version.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FishFinder {

	public ref class frmAbout : public System::Windows::Forms::Form
	{
	public:
		frmAbout( String^ name, String^ close, String^ translation_credits )
		{
			InitializeComponent();

			Text = name->Replace( L"&", L"" );
			
			lblVersion->Text = L"Version " + STRINGIZE( VERSION_NO );

			btnClose->Text = close;

			if( translation_credits )
			{
				this->Height += 20;

				Label^ l = gcnew Label();
				l->AutoSize = true;
				l->Name = L"lblTranslation";
				l->Text = translation_credits;
				l->Size = TextRenderer::MeasureText( l->Text, l->Font );
				l->Location = System::Drawing::Point( ( this->Width - l->Width ) / 2, 250 );

				this->Controls->Add( l );
			}

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
		}

	protected:

		~frmAbout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Label^  lblName;
	private: System::Windows::Forms::Label^  lblVersion;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmAbout::typeid));
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnClose->Location = System::Drawing::Point(94, 250);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(75, 23);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmAbout::btnClose_Click);
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(35, 204);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(206, 13);
			this->lblName->TabIndex = 1;
			this->lblName->Text = L"Athena\'s Fish Finder for MH3G and MH3U";
			// 
			// lblVersion
			// 
			this->lblVersion->AutoSize = true;
			this->lblVersion->Location = System::Drawing::Point(94, 230);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(75, 13);
			this->lblVersion->TabIndex = 2;
			this->lblVersion->Text = L"Version X.XXb";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(15, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(244, 191);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// frmAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(276, 280);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblVersion);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->btnClose);
			this->Name = L"frmAbout";
			this->Text = L"About";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Close();
		}
	};
}
