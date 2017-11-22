#pragma once
#include "frmAbout.h"
#include "Version.h"

enum
{
	iEnglish = 0,
	iFile,
	iQuit,
	iLanguage,
	iHelp,
	iAbout,
	iClear,
	iClose,
	iHaul,
	iItem,
};

namespace FishFinder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
		array< int, 2 >^ indices;
		array< unsigned >^ row_result;
		ComboBox^ selected_box;
		int old_table_selection;
		bool changing_selection, initialized;

	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item2;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item3;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item4;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item6;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item7;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item8;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Item9;

	private: System::Windows::Forms::DataGridView^  dataFish;
	private: System::Windows::Forms::DataGridView^  dataTables;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T1;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T2;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T3;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T4;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T5;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T6;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T7;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T8;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T9;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T10;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T11;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T12;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T13;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T14;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T15;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T16;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  T17;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFile;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuQuit;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuLanguage;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuAbout;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuEnglish;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFrench;


#pragma region English
		static array< String^ >^ items_eng =
		{
			L"",
			L"Shining Starfish x1",
			L"Pin Tuna x2",
			L"Shining Starfish x2",
			L"Sushifish x2",
			L"Popfish x5",
			L"Sushifish x3",
			L"Whetfish x6",
			L"Sleepyfish x2",
			L"Popfish x4",
			L"Whetfish x4",
			L"Humspun Conch"
		};
		static array< String^ >^ strings_eng =
		{
			L"&English",
			L"&File",
			L"&Quit",
			L"&Language",
			L"&Help",
			L"&About",
			L"&Clear",
			L"&Close",
			L"Haul",
			L"Item",
		};
#pragma endregion
#pragma region French
			 static array< String^ >^ items_fr =
			 {
				 L"",
				 L"Étoile brillante ×1",
				 L"Pointhon ×2",
				 L"Étoile brillante ×2",
				 L"Sushipoisson ×2",
				 L"Poisséclate ×5",
				 L"Sushipoisson ×3",
				 L"Poissaiguiseur ×6",
				 L"Somnipoisson ×2",
				 L"Poisséclate ×4",
				 L"Poissaiguiseur ×4",
				 L"Méloconque"
			 };
			 static array< String^ >^ strings_fr =
			 {
				 L"&Français",
				 L"&Fichier",
				 L"&Quitter",
				 L"&Language",
				 L"&Aide",
				 L"À &propos",
				 L"&Réinitialiser",
				 L"&Fermer",
				 L"Prise de pêche",
				 L"Objet",
			 };
#pragma endregion
		
	public:
		Form1(void) : initialized( false )
		{
			InitializeComponent();

			Text += L" " + STRINGIZE( VERSION_NO );

			mnuEnglish->Checked = true;

			dataFish->Rows->Add( 10 );
			row_result = gcnew array< unsigned >( dataFish->RowCount );
			for( int i = 0; i < dataFish->RowCount; ++i )
			{
				dataFish->Rows[i]->HeaderCell->Value = L"Haul " + (i+1);
				row_result[ i ] = ~0;
			}
			
			indices = gcnew array< int, 2 >( dataFish->RowCount, dataFish->ColumnCount );

			for( int c = 0; c < dataFish->ColumnCount; ++c )
			{
				for( int r = 0; r < dataFish->RowCount; ++r )
				{
					System::Windows::Forms::DataGridViewComboBoxCell^ cell = safe_cast< System::Windows::Forms::DataGridViewComboBoxCell^ >( dataFish[c,r] );
					cell->Items->AddRange( items_eng );
				}
			}
			dataFish->CurrentCellDirtyStateChanged += gcnew EventHandler( this, &Form1::DataChanged );
			dataFish->CellValueChanged += gcnew DataGridViewCellEventHandler( this, &Form1::CellValueChanged );
			dataFish->EditingControlShowing += gcnew DataGridViewEditingControlShowingEventHandler( this, &Form1::BoxShown );
			dataFish->CellClick += gcnew DataGridViewCellEventHandler( this, &Form1::CellEntered );

			dataFish->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::None;

			dataTables->Rows->Add(1);
			dataTables->SelectionChanged += gcnew EventHandler( this, &Form1::tableSelectionChanged );
			dataTables->ClearSelection();
			old_table_selection = -1;
			changing_selection = false;
			dataTables->Columns[ 10 ]->HeaderCell->Style->ForeColor = Color::Red;
			dataTables->Columns[ 11 ]->HeaderCell->Style->ForeColor = Color::Red;
			dataTables->Columns[ 14 ]->HeaderCell->Style->ForeColor = Color::Red;
			dataTables->Columns[ 15 ]->HeaderCell->Style->ForeColor = Color::Red;
			dataTables->Columns[ 16 ]->HeaderCell->Style->ForeColor = Color::Red;

			initialized = true;
		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataFish = (gcnew System::Windows::Forms::DataGridView());
			this->Item1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item2 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item3 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item4 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item5 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item6 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item7 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item8 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Item9 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->dataTables = (gcnew System::Windows::Forms::DataGridView());
			this->T1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T2 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T3 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T4 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T5 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T6 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T7 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T8 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T9 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T10 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T11 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T12 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T13 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T14 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T15 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T16 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->T17 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuQuit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuLanguage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuEnglish = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFrench = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataFish))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTables))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataFish
			// 
			this->dataFish->AllowUserToAddRows = false;
			this->dataFish->AllowUserToDeleteRows = false;
			this->dataFish->AllowUserToOrderColumns = true;
			this->dataFish->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataFish->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataFish->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataFish->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->Item1, this->Item2, 
				this->Item3, this->Item4, this->Item5, this->Item6, this->Item7, this->Item8, this->Item9});
			this->dataFish->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataFish->EnableHeadersVisualStyles = false;
			this->dataFish->Location = System::Drawing::Point(12, 27);
			this->dataFish->MultiSelect = false;
			this->dataFish->Name = L"dataFish";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataFish->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataFish->RowHeadersWidth = 80;
			this->dataFish->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataFish->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataFish->ShowEditingIcon = false;
			this->dataFish->Size = System::Drawing::Size(1115, 238);
			this->dataFish->TabIndex = 0;
			// 
			// Item1
			// 
			this->Item1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item1->HeaderText = L"Item 1";
			this->Item1->Name = L"Item1";
			this->Item1->Width = 115;
			// 
			// Item2
			// 
			this->Item2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item2->HeaderText = L"Item2";
			this->Item2->Name = L"Item2";
			this->Item2->Width = 115;
			// 
			// Item3
			// 
			this->Item3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item3->HeaderText = L"Item 3";
			this->Item3->Name = L"Item3";
			this->Item3->Width = 115;
			// 
			// Item4
			// 
			this->Item4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item4->HeaderText = L"Item 4";
			this->Item4->Name = L"Item4";
			this->Item4->Width = 115;
			// 
			// Item5
			// 
			this->Item5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item5->HeaderText = L"Item 5";
			this->Item5->Name = L"Item5";
			this->Item5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Item5->Width = 115;
			// 
			// Item6
			// 
			this->Item6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item6->HeaderText = L"Item 6";
			this->Item6->Name = L"Item6";
			this->Item6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Item6->Width = 115;
			// 
			// Item7
			// 
			this->Item7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item7->HeaderText = L"Item 7";
			this->Item7->Name = L"Item7";
			this->Item7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Item7->Width = 115;
			// 
			// Item8
			// 
			this->Item8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item8->HeaderText = L"Item 8";
			this->Item8->Name = L"Item8";
			this->Item8->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Item8->Width = 115;
			// 
			// Item9
			// 
			this->Item9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Item9->HeaderText = L"Item 9";
			this->Item9->Name = L"Item9";
			this->Item9->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Item9->Width = 115;
			// 
			// dataTables
			// 
			this->dataTables->AllowUserToAddRows = false;
			this->dataTables->AllowUserToDeleteRows = false;
			this->dataTables->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dataTables->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataTables->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataTables->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(17) {this->T1, this->T2, 
				this->T3, this->T4, this->T5, this->T6, this->T7, this->T8, this->T9, this->T10, this->T11, this->T12, this->T13, this->T14, 
				this->T15, this->T16, this->T17});
			this->dataTables->EnableHeadersVisualStyles = false;
			this->dataTables->Location = System::Drawing::Point(12, 271);
			this->dataTables->MultiSelect = false;
			this->dataTables->Name = L"dataTables";
			this->dataTables->ReadOnly = true;
			this->dataTables->RowHeadersVisible = false;
			this->dataTables->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataTables->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataTables->ShowEditingIcon = false;
			this->dataTables->Size = System::Drawing::Size(814, 40);
			this->dataTables->TabIndex = 1;
			// 
			// T1
			// 
			this->T1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T1->HeaderText = L"T1";
			this->T1->Name = L"T1";
			this->T1->ReadOnly = true;
			this->T1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T1->Width = 45;
			// 
			// T2
			// 
			this->T2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T2->HeaderText = L"T2";
			this->T2->Name = L"T2";
			this->T2->ReadOnly = true;
			this->T2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T2->Width = 45;
			// 
			// T3
			// 
			this->T3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T3->HeaderText = L"T3";
			this->T3->Name = L"T3";
			this->T3->ReadOnly = true;
			this->T3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T3->Width = 45;
			// 
			// T4
			// 
			this->T4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T4->HeaderText = L"T4";
			this->T4->Name = L"T4";
			this->T4->ReadOnly = true;
			this->T4->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T4->Width = 45;
			// 
			// T5
			// 
			this->T5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T5->HeaderText = L"T5";
			this->T5->Name = L"T5";
			this->T5->ReadOnly = true;
			this->T5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T5->Width = 45;
			// 
			// T6
			// 
			this->T6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T6->HeaderText = L"T6";
			this->T6->Name = L"T6";
			this->T6->ReadOnly = true;
			this->T6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T6->Width = 45;
			// 
			// T7
			// 
			this->T7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T7->HeaderText = L"T7";
			this->T7->Name = L"T7";
			this->T7->ReadOnly = true;
			this->T7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T7->Width = 45;
			// 
			// T8
			// 
			this->T8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T8->HeaderText = L"T8";
			this->T8->Name = L"T8";
			this->T8->ReadOnly = true;
			this->T8->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T8->Width = 45;
			// 
			// T9
			// 
			this->T9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T9->HeaderText = L"T9";
			this->T9->Name = L"T9";
			this->T9->ReadOnly = true;
			this->T9->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T9->Width = 45;
			// 
			// T10
			// 
			this->T10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T10->HeaderText = L"T10";
			this->T10->Name = L"T10";
			this->T10->ReadOnly = true;
			this->T10->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T10->Width = 51;
			// 
			// T11
			// 
			this->T11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T11->HeaderText = L"T11";
			this->T11->Name = L"T11";
			this->T11->ReadOnly = true;
			this->T11->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T11->Width = 51;
			// 
			// T12
			// 
			this->T12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T12->HeaderText = L"T12";
			this->T12->Name = L"T12";
			this->T12->ReadOnly = true;
			this->T12->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T12->Width = 51;
			// 
			// T13
			// 
			this->T13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T13->HeaderText = L"T13";
			this->T13->Name = L"T13";
			this->T13->ReadOnly = true;
			this->T13->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T13->Width = 51;
			// 
			// T14
			// 
			this->T14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T14->HeaderText = L"T14";
			this->T14->Name = L"T14";
			this->T14->ReadOnly = true;
			this->T14->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T14->Width = 51;
			// 
			// T15
			// 
			this->T15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T15->HeaderText = L"T15";
			this->T15->Name = L"T15";
			this->T15->ReadOnly = true;
			this->T15->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T15->Width = 51;
			// 
			// T16
			// 
			this->T16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T16->HeaderText = L"T16";
			this->T16->Name = L"T16";
			this->T16->ReadOnly = true;
			this->T16->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->T16->Width = 51;
			// 
			// T17
			// 
			this->T17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->T17->HeaderText = L"T17";
			this->T17->Name = L"T17";
			this->T17->ReadOnly = true;
			this->T17->Width = 51;
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(832, 271);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(78, 40);
			this->btnClear->TabIndex = 2;
			this->btnClear->Text = L"&Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuFile, this->mnuLanguage, 
				this->mnuHelp});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1141, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mnuFile
			// 
			this->mnuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mnuQuit});
			this->mnuFile->Name = L"mnuFile";
			this->mnuFile->Size = System::Drawing::Size(37, 20);
			this->mnuFile->Text = L"&File";
			// 
			// mnuQuit
			// 
			this->mnuQuit->Name = L"mnuQuit";
			this->mnuQuit->Size = System::Drawing::Size(152, 22);
			this->mnuQuit->Text = L"&Quit";
			this->mnuQuit->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// mnuLanguage
			// 
			this->mnuLanguage->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mnuEnglish, 
				this->mnuFrench});
			this->mnuLanguage->Name = L"mnuLanguage";
			this->mnuLanguage->Size = System::Drawing::Size(71, 20);
			this->mnuLanguage->Text = L"&Language";
			// 
			// mnuEnglish
			// 
			this->mnuEnglish->Name = L"mnuEnglish";
			this->mnuEnglish->Size = System::Drawing::Size(152, 22);
			this->mnuEnglish->Text = L"&English";
			this->mnuEnglish->Click += gcnew System::EventHandler(this, &Form1::englishToolStripMenuItem_Click);
			// 
			// mnuFrench
			// 
			this->mnuFrench->Name = L"mnuFrench";
			this->mnuFrench->Size = System::Drawing::Size(152, 22);
			this->mnuFrench->Text = L"&Français";
			this->mnuFrench->Click += gcnew System::EventHandler(this, &Form1::francaisToolStripMenuItem_Click);
			// 
			// mnuHelp
			// 
			this->mnuHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mnuAbout});
			this->mnuHelp->Name = L"mnuHelp";
			this->mnuHelp->Size = System::Drawing::Size(44, 20);
			this->mnuHelp->Text = L"&Help";
			// 
			// mnuAbout
			// 
			this->mnuAbout->Name = L"mnuAbout";
			this->mnuAbout->Size = System::Drawing::Size(152, 22);
			this->mnuAbout->Text = L"&About";
			this->mnuAbout->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1141, 423);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->dataTables);
			this->Controls->Add(this->dataFish);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Athena\'s Fish Finder";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataFish))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataTables))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		System::Void DataChanged(System::Object^  sender, EventArgs^  e)
		{
			if( dataFish->IsCurrentCellDirty )
			{
				dataFish->CommitEdit( DataGridViewDataErrorContexts::Commit );
				DataGridViewCell^ cell = dataFish->CurrentCell;
				RecalculateRow( cell->RowIndex );
			}
		}

		System::Void BoxShown( System::Object^ sender, DataGridViewEditingControlShowingEventArgs^ e )
		{
			selected_box = safe_cast< ComboBox^ >( e->Control );
		}

		System::Void tableSelectionChanged( System::Object^  sender, EventArgs^  e )
		{
			if( changing_selection )
				return;
			changing_selection = true;
			
			dataTables->ClearSelection();
			if( old_table_selection >= 0 )
				dataTables[ old_table_selection, 0 ]->Selected = true;
			
			changing_selection = false;
		}

		System::Void CellEntered( System::Object^ sender, DataGridViewCellEventArgs^ e )
		{
			if( !initialized || e->ColumnIndex < 0 || e->RowIndex < 0 )
				return;
			dataFish->CurrentCell = dataFish[ e->ColumnIndex, e->RowIndex ];
			dataFish->BeginEdit( false );
			ComboBox^ box = safe_cast< ComboBox^ >( dataFish->EditingControl );
			if( box )
			{
				box->DroppedDown = true;
			}
		}

		System::Void CellValueChanged( System::Object^ sender, DataGridViewCellEventArgs^ e )
		{
			DataGridViewCell^ cell = dataFish->CurrentCell;
			if( cell && selected_box )
			{
				indices[ cell->RowIndex, cell->ColumnIndex ] = selected_box->SelectedIndex;
			}
		}

		System::Void RecalculateRow( const unsigned row )
		{
			Generic::List< unsigned > items;
			for( int i = 0; i < dataFish->ColumnCount; ++i )
				if( indices[ row, i ] > 0 )
					items.Add( indices[ row, i ] - 1 );
			if( items.Count == 0 )
				row_result[ row ] = ~0;
			else row_result[ row ] = GetTableResults( items.ToArray() );

			if( row_result[ row ] == 0 ) 
				dataFish->Rows[ row ]->HeaderCell->Style->BackColor = Color::Red;
			else
				dataFish->Rows[ row ]->HeaderCell->Style->BackColor = dataFish->DefaultBackColor;
			dataFish->InvalidateRow( row );

			unsigned n = ~0;
			for( int j = 0; j < dataFish->RowCount; ++j )
			{
				if( row_result[ j ] != 0 )
					n &= row_result[ j ];
			}

			dataTables->SuspendLayout();
			unsigned num_tables = 0, table_index = -1;
			for( int i = 0; i < dataTables->ColumnCount; ++i )
			{
				DataGridViewCheckBoxCell^ cell = safe_cast< DataGridViewCheckBoxCell^ >( dataTables[ i, 0 ] );
				if( n & ( 1 << i ) )
				{
					cell->Value = true;
					num_tables++;
					table_index = i;
				}
				else
					cell->Value = false;
			}
			changing_selection = true;
			dataTables->ClearSelection();
			old_table_selection = -1;
			if( num_tables == 1 )
			{
				old_table_selection = table_index;
				dataTables[ table_index, 0 ]->Selected = true;
			}
			changing_selection = false;
			dataTables->ResumeLayout();
		}

		// --------- Fancy shit here ---------

		int rnd( const int n )
		{
			if( n == 0 ) return 176;

			int x = n * 16 - n * 4 - n;
			long long y = x * 16;
			long long z = y * 11367737L / 4294967296L;
			long long m = y - ( ( y - z ) / 2L + z ) / 32768L * 65363L;
			return (int)( m & 0xFFFF );
		}

		unsigned GetFishIndex( const unsigned roll, array< unsigned >^ fish )
		{
			unsigned total = fish[ 0 ], count = 0;
			while( total <= roll )
			{
				total += fish[ ++count ];
			}
			return count;
		}

		unsigned reward_func( unsigned num, const unsigned rep )
		{
			for( unsigned i = 0; i < rep; ++i )
				num = ( num * 176 ) % 65363;
			return num;
		}

		bool ArrayEquals( array< unsigned >^ a, const unsigned as, array< unsigned >^ b, const unsigned bs, const unsigned len )
		{
			for( unsigned i = 0; i < len; ++i )
				if( a[ as + i ] != b[ bs + i ] )
					return false;
			return true;
		}

		template< typename T >
		T Clamp( const T val, const T min_val, const T max_val )
		{
			return Math::Max( Math::Min( val, max_val ), min_val );
		}

		bool SearchSeed( const unsigned seed, array< unsigned >^ fish_table, array< unsigned >^ items )
		{
			//const unsigned test = ( seed * 176 ) % 65363;
			array< unsigned >^ qwe = gcnew array< unsigned >( 13 );
			for( int j = 0; j < qwe->Length; )
			{
				const unsigned roll = reward_func( seed, ++j ) % 100;
				qwe[j-1] = GetFishIndex( roll, fish_table );
			}
			const unsigned max_fishfinder = Clamp( items->Length, 4, 7 ) - 4;
			for( unsigned i = 0; i <= max_fishfinder; ++i )
			{
				if( ArrayEquals( qwe, 0, items, 0, items->Length - i ) &&
					ArrayEquals( qwe, 10, items, items->Length - i, i ) )
					return true;
			}
			/*if( items->Length <= 7 )
			{
				if( ArrayEquals( qwe, 0, items, 0, items->Length ) )
					return true;
			}
			if( items->Length >= 7 )
			{
				if( ArrayEquals( qwe, 0, items, 0, items->Length - 3 ) &&
					ArrayEquals( qwe, 10, items, items->Length - 3, 3 ) )
					return true;
			}*/
			return false;
		}

		bool CheckSeed( const int seed, array< unsigned >^ fish_table, array< unsigned >^ items )
		{
			int n = seed;
			do
			{
				if( SearchSeed( n, fish_table, items ) )
					return true;

				n = rnd( n );
			}
			while( n != seed );
			return false;
		}

		unsigned GetTableResults( array< unsigned >^ items )
		{
			enum FishRewards
			{
				ShiningStarfishx1 = 0,
				PinTunax2 = 1,
				ShiningStarfishx2 = 2,
				Sushifishx2 = 3,
				Popfishx5 = 4,
				Sushifishx3 = 5,
				Whetfishx6 = 6,
				Sleepyfishx2 = 7,
				Popfishx4 = 8,
				Whetfishx4 = 9,
				HumspunConch = 10,
			};

			array< int >^ table_seeds = { 1, 15, 5, 13, 4, 3, 9, 12, 26, 18, 163, 401, 6, 2, 489, 802, 1203 };
			array< unsigned >^ fish = { 20, 15, 5, 5, 10, 15, 5, 10, 5, 5, 5 };

			unsigned res = 0;
			for( unsigned t = 0; t < 17; ++t )
			{
				if( CheckSeed( table_seeds[ t ], fish, items ) )
					res |= 1 << t;
			}
			return res;
		}

		System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e)
		{
			changing_selection = false;
			selected_box = nullptr;
			dataFish->SuspendLayout();

			old_table_selection = -1;
			dataTables->ClearSelection();

			for( int j = 0; j < row_result->Length; ++j )
				row_result[ j ] = ~0;

			for( int j = 0; j < dataFish->RowCount; ++j )
			{
				for( int i = 0; i < dataFish->ColumnCount; ++i )
				{
					indices[ j, i ] = 0;
					dataFish[ i, j ]->Value = L"";
					indices[ j, i ] = 0;
				}
			}
			for( int j = 0; j < dataFish->RowCount; ++j )
				dataFish->Rows[ j ]->HeaderCell->Style->BackColor = dataFish->DefaultBackColor;
			for( unsigned i = 0; i < 17; ++i )
			{
				DataGridViewCheckBoxCell^ cell = safe_cast< DataGridViewCheckBoxCell^ >( dataTables[ i, 0 ] );
				cell->Value = false;
			}
			dataFish->ResumeLayout();
		}

		System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Close();
		}

		System::Void aboutToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if( mnuEnglish->Checked )
			{
				frmAbout f( strings_eng[ iAbout ], strings_eng[ iClose ], nullptr );
				f.ShowDialog();
			}
			else
			{
				frmAbout f( strings_fr[ iAbout ], strings_fr[ iClose ], L"(Traduction française : RainbowRollD)" );
				f.ShowDialog();
			}
		}
	
		System::Void englishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			UpdateLanguage( items_eng, strings_eng );
			mnuEnglish->Checked = true;
			mnuFrench->Checked = false;
		}

		System::Void francaisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			UpdateLanguage( items_fr, strings_fr );
			mnuEnglish->Checked = false;
			mnuFrench->Checked = true;
		}

		void UpdateLanguage( array< String^ >^ items, array< String^ >^ strings )
		{
			dataFish->CurrentCell = nullptr;
				
			mnuFile->Text = strings[ iFile ];
			mnuQuit->Text = strings[ iQuit ];
			mnuLanguage->Text = strings[ iLanguage ];
			mnuHelp->Text = strings[ iHelp ];
			mnuAbout->Text = strings[ iAbout ];
			btnClear->Text = strings[ iClear ];

			dataFish->SuspendLayout();
			for( int i = 0; i < dataFish->RowCount; ++i )
			{
				dataFish->Rows[i]->HeaderCell->Value = strings[ iHaul ] + L" " + (i+1);
			}

			for( int i = 0; i < dataFish->ColumnCount; ++i )
			{
				dataFish->Columns[i]->HeaderCell->Value = strings[ iItem ] + L" " + (i+1);
			}
			
			const int new_width = TextRenderer::MeasureText( strings[ iHaul ] + L" 10", dataFish->Font ).Width + 36;
			Width += new_width - dataFish->RowHeadersWidth;
			dataFish->RowHeadersWidth = new_width;
			
			for( int c = 0; c < dataFish->ColumnCount; ++c )
			{
				for( int r = 0; r < dataFish->RowCount; ++r )
				{
					System::Windows::Forms::DataGridViewComboBoxCell^ cell = safe_cast< System::Windows::Forms::DataGridViewComboBoxCell^ >( dataFish[c,r] );
					cell->Value = L"";
					for( int i = 0; i < items->Length; ++i )
						cell->Items[ i ] = items[ i ];
					cell->Value = items[ indices[ r,c ] ];
				}
			}
			dataFish->ResumeLayout();
		}
};
}
