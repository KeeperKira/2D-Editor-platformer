#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RedactorLeve01 {

	/// <summary>
	/// Summary for ConfigImage
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ConfigImage : public System::Windows::Forms::Form
	{
	public:
		ConfigImage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Pos		=	new	POINT;
			Loc		=	new	POINT;
			LastPos	=	new	POINT;
			CoImage	=	new	DECOR;
			CoImage->CreateImage(10,10);
		}

	protected:
		/// <summary>
	public:	DECOR	*CoImage;
			POINT *LastPos,*Pos,*Loc;
	private: System::Windows::Forms::TabControl^  tabControl1;
	public: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  groupBox2;


	private: System::Windows::Forms::RadioButton^  radioButton24;

	private: System::Windows::Forms::RadioButton^  radioButton26;

	private: System::Windows::Forms::RadioButton^  radioButton28;
	private: System::Windows::Forms::RadioButton^  radioButton29;
	private: System::Windows::Forms::RadioButton^  radioButton30;
	private: System::Windows::Forms::RadioButton^  radioButton31;

	private: System::Windows::Forms::RadioButton^  radioButton33;

	private: System::Windows::Forms::RadioButton^  radioButton35;
	private: System::Windows::Forms::RadioButton^  radioButton36;

	private: System::Windows::Forms::RadioButton^  radioButton38;
	private: System::Windows::Forms::RadioButton^  radioButton39;
	private: System::Windows::Forms::RadioButton^  radioButton40;
	private: System::Windows::Forms::RadioButton^  radioButton41;
	private: System::Windows::Forms::RadioButton^  radioButton42;
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::Windows::Forms::RadioButton^  radioButton8;

	private: System::Windows::Forms::RadioButton^  radioButton15;

	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton14;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton13;

	private: System::Windows::Forms::RadioButton^  radioButton2;

	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton11;

	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton1;

















	private: System::Windows::Forms::CheckBox^  checkBox1;
	public: 
		/// Clean up any resources being used.
		/// </summary>
		~ConfigImage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar6;

	private: System::Windows::Forms::TrackBar^  trackBar5;

	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TrackBar^  trackBar8;
	private: System::Windows::Forms::TrackBar^  trackBar7;
	private: System::Windows::Forms::Label^  label8;


	protected: 



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ConfigImage::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar8 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton24 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton26 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton28 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton29 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton30 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton31 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton33 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton35 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton36 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton38 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton39 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton40 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton41 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton42 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar7))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->trackBar6);
			this->panel1->Controls->Add(this->trackBar5);
			this->panel1->Controls->Add(this->trackBar2);
			this->panel1->Controls->Add(this->trackBar1);
			this->panel1->Controls->Add(this->label1);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConfigImage::panel1_Paint);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::panel1_MouseMove);
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// trackBar6
			// 
			this->trackBar6->LargeChange = 10;
			resources->ApplyResources(this->trackBar6, L"trackBar6");
			this->trackBar6->Maximum = 255;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->TabStop = false;
			this->trackBar6->TickFrequency = 25;
			this->trackBar6->Value = 255;
			this->trackBar6->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar6_ValueChanged);
			// 
			// trackBar5
			// 
			this->trackBar5->LargeChange = 10;
			resources->ApplyResources(this->trackBar5, L"trackBar5");
			this->trackBar5->Maximum = 255;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->TabStop = false;
			this->trackBar5->TickFrequency = 25;
			this->trackBar5->Value = 255;
			this->trackBar5->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar5_ValueChanged);
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 10;
			resources->ApplyResources(this->trackBar2, L"trackBar2");
			this->trackBar2->Maximum = 255;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->TabStop = false;
			this->trackBar2->TickFrequency = 25;
			this->trackBar2->Value = 255;
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar2_ValueChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 10;
			resources->ApplyResources(this->trackBar1, L"trackBar1");
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->TickFrequency = 25;
			this->trackBar1->Value = 255;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar1_ValueChanged);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->trackBar8);
			this->panel2->Controls->Add(this->trackBar7);
			this->panel2->Controls->Add(this->label6);
			resources->ApplyResources(this->panel2, L"panel2");
			this->panel2->Name = L"panel2";
			this->panel2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::panel2_MouseMove);
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::checkBox1_CheckedChanged);
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// trackBar8
			// 
			this->trackBar8->LargeChange = 1;
			resources->ApplyResources(this->trackBar8, L"trackBar8");
			this->trackBar8->Maximum = 628;
			this->trackBar8->Name = L"trackBar8";
			this->trackBar8->TabStop = false;
			this->trackBar8->TickFrequency = 62;
			this->trackBar8->Scroll += gcnew System::EventHandler(this, &ConfigImage::trackBar8_Scroll);
			this->trackBar8->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar8_ValueChanged);
			// 
			// trackBar7
			// 
			this->trackBar7->LargeChange = 10;
			resources->ApplyResources(this->trackBar7, L"trackBar7");
			this->trackBar7->Maximum = 100;
			this->trackBar7->Minimum = -100;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->TabStop = false;
			this->trackBar7->TickFrequency = 50;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &ConfigImage::trackBar7_Scroll);
			this->trackBar7->ValueChanged += gcnew System::EventHandler(this, &ConfigImage::trackBar7_ValueChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			resources->ApplyResources(this->tabControl1, L"tabControl1");
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::tabControl1_MouseMove);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::RoyalBlue;
			this->tabPage1->Controls->Add(this->panel1);
			this->tabPage1->Controls->Add(this->panel2);
			resources->ApplyResources(this->tabPage1, L"tabPage1");
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::tabPage1_MouseMove);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::RoyalBlue;
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			resources->ApplyResources(this->tabPage2, L"tabPage2");
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::tabPage2_MouseMove);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton24);
			this->groupBox2->Controls->Add(this->radioButton26);
			this->groupBox2->Controls->Add(this->radioButton28);
			this->groupBox2->Controls->Add(this->radioButton29);
			this->groupBox2->Controls->Add(this->radioButton30);
			this->groupBox2->Controls->Add(this->radioButton31);
			this->groupBox2->Controls->Add(this->radioButton33);
			this->groupBox2->Controls->Add(this->radioButton35);
			this->groupBox2->Controls->Add(this->radioButton36);
			this->groupBox2->Controls->Add(this->radioButton38);
			this->groupBox2->Controls->Add(this->radioButton39);
			this->groupBox2->Controls->Add(this->radioButton40);
			this->groupBox2->Controls->Add(this->radioButton41);
			this->groupBox2->Controls->Add(this->radioButton42);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			// 
			// radioButton24
			// 
			resources->ApplyResources(this->radioButton24, L"radioButton24");
			this->radioButton24->Name = L"radioButton24";
			this->radioButton24->TabStop = true;
			this->radioButton24->UseVisualStyleBackColor = true;
			this->radioButton24->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton24_CheckedChanged);
			// 
			// radioButton26
			// 
			resources->ApplyResources(this->radioButton26, L"radioButton26");
			this->radioButton26->Name = L"radioButton26";
			this->radioButton26->TabStop = true;
			this->radioButton26->UseVisualStyleBackColor = true;
			this->radioButton26->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton26_CheckedChanged);
			// 
			// radioButton28
			// 
			resources->ApplyResources(this->radioButton28, L"radioButton28");
			this->radioButton28->Name = L"radioButton28";
			this->radioButton28->TabStop = true;
			this->radioButton28->UseVisualStyleBackColor = true;
			this->radioButton28->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton28_CheckedChanged);
			// 
			// radioButton29
			// 
			resources->ApplyResources(this->radioButton29, L"radioButton29");
			this->radioButton29->Name = L"radioButton29";
			this->radioButton29->TabStop = true;
			this->radioButton29->UseVisualStyleBackColor = true;
			this->radioButton29->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton29_CheckedChanged);
			// 
			// radioButton30
			// 
			resources->ApplyResources(this->radioButton30, L"radioButton30");
			this->radioButton30->Name = L"radioButton30";
			this->radioButton30->TabStop = true;
			this->radioButton30->UseVisualStyleBackColor = true;
			this->radioButton30->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton30_CheckedChanged);
			// 
			// radioButton31
			// 
			resources->ApplyResources(this->radioButton31, L"radioButton31");
			this->radioButton31->Name = L"radioButton31";
			this->radioButton31->TabStop = true;
			this->radioButton31->UseVisualStyleBackColor = true;
			this->radioButton31->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton31_CheckedChanged);
			// 
			// radioButton33
			// 
			resources->ApplyResources(this->radioButton33, L"radioButton33");
			this->radioButton33->Name = L"radioButton33";
			this->radioButton33->TabStop = true;
			this->radioButton33->UseVisualStyleBackColor = true;
			this->radioButton33->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton33_CheckedChanged);
			// 
			// radioButton35
			// 
			resources->ApplyResources(this->radioButton35, L"radioButton35");
			this->radioButton35->Name = L"radioButton35";
			this->radioButton35->TabStop = true;
			this->radioButton35->UseVisualStyleBackColor = true;
			this->radioButton35->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton35_CheckedChanged);
			// 
			// radioButton36
			// 
			resources->ApplyResources(this->radioButton36, L"radioButton36");
			this->radioButton36->Name = L"radioButton36";
			this->radioButton36->TabStop = true;
			this->radioButton36->UseVisualStyleBackColor = true;
			this->radioButton36->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton36_CheckedChanged);
			// 
			// radioButton38
			// 
			resources->ApplyResources(this->radioButton38, L"radioButton38");
			this->radioButton38->Name = L"radioButton38";
			this->radioButton38->TabStop = true;
			this->radioButton38->UseVisualStyleBackColor = true;
			this->radioButton38->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton38_CheckedChanged);
			// 
			// radioButton39
			// 
			resources->ApplyResources(this->radioButton39, L"radioButton39");
			this->radioButton39->Name = L"radioButton39";
			this->radioButton39->TabStop = true;
			this->radioButton39->UseVisualStyleBackColor = true;
			this->radioButton39->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton39_CheckedChanged);
			// 
			// radioButton40
			// 
			resources->ApplyResources(this->radioButton40, L"radioButton40");
			this->radioButton40->Name = L"radioButton40";
			this->radioButton40->TabStop = true;
			this->radioButton40->UseVisualStyleBackColor = true;
			this->radioButton40->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton40_CheckedChanged);
			// 
			// radioButton41
			// 
			resources->ApplyResources(this->radioButton41, L"radioButton41");
			this->radioButton41->Name = L"radioButton41";
			this->radioButton41->TabStop = true;
			this->radioButton41->UseVisualStyleBackColor = true;
			this->radioButton41->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton41_CheckedChanged);
			// 
			// radioButton42
			// 
			resources->ApplyResources(this->radioButton42, L"radioButton42");
			this->radioButton42->Name = L"radioButton42";
			this->radioButton42->TabStop = true;
			this->radioButton42->UseVisualStyleBackColor = true;
			this->radioButton42->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton42_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton8);
			this->groupBox1->Controls->Add(this->radioButton15);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton14);
			this->groupBox1->Controls->Add(this->radioButton7);
			this->groupBox1->Controls->Add(this->radioButton13);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton6);
			this->groupBox1->Controls->Add(this->radioButton11);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton10);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton9);
			this->groupBox1->Controls->Add(this->radioButton1);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// radioButton8
			// 
			resources->ApplyResources(this->radioButton8, L"radioButton8");
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->TabStop = true;
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton8_CheckedChanged);
			// 
			// radioButton15
			// 
			resources->ApplyResources(this->radioButton15, L"radioButton15");
			this->radioButton15->Name = L"radioButton15";
			this->radioButton15->TabStop = true;
			this->radioButton15->UseVisualStyleBackColor = true;
			this->radioButton15->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton15_CheckedChanged);
			// 
			// radioButton4
			// 
			resources->ApplyResources(this->radioButton4, L"radioButton4");
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->TabStop = true;
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton4_CheckedChanged);
			// 
			// radioButton14
			// 
			resources->ApplyResources(this->radioButton14, L"radioButton14");
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->TabStop = true;
			this->radioButton14->UseVisualStyleBackColor = true;
			this->radioButton14->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton14_CheckedChanged);
			// 
			// radioButton7
			// 
			resources->ApplyResources(this->radioButton7, L"radioButton7");
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->TabStop = true;
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton7_CheckedChanged);
			// 
			// radioButton13
			// 
			resources->ApplyResources(this->radioButton13, L"radioButton13");
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->TabStop = true;
			this->radioButton13->UseVisualStyleBackColor = true;
			this->radioButton13->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton13_CheckedChanged);
			// 
			// radioButton2
			// 
			resources->ApplyResources(this->radioButton2, L"radioButton2");
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->TabStop = true;
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton2_CheckedChanged);
			// 
			// radioButton6
			// 
			resources->ApplyResources(this->radioButton6, L"radioButton6");
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->TabStop = true;
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton6_CheckedChanged);
			// 
			// radioButton11
			// 
			resources->ApplyResources(this->radioButton11, L"radioButton11");
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->TabStop = true;
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton11_CheckedChanged);
			// 
			// radioButton3
			// 
			resources->ApplyResources(this->radioButton3, L"radioButton3");
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->TabStop = true;
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton3_CheckedChanged);
			// 
			// radioButton10
			// 
			resources->ApplyResources(this->radioButton10, L"radioButton10");
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->TabStop = true;
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton10_CheckedChanged);
			// 
			// radioButton5
			// 
			resources->ApplyResources(this->radioButton5, L"radioButton5");
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->TabStop = true;
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton5_CheckedChanged);
			// 
			// radioButton9
			// 
			resources->ApplyResources(this->radioButton9, L"radioButton9");
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->TabStop = true;
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton9_CheckedChanged);
			// 
			// radioButton1
			// 
			resources->ApplyResources(this->radioButton1, L"radioButton1");
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &ConfigImage::radioButton1_CheckedChanged);
			// 
			// ConfigImage
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(79)), static_cast<System::Int32>(static_cast<System::Byte>(134)), 
				static_cast<System::Int32>(static_cast<System::Byte>(174)));
			this->ControlBox = false;
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ConfigImage";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Load += gcnew System::EventHandler(this, &ConfigImage::ConfigImage_Load);
			this->Shown += gcnew System::EventHandler(this, &ConfigImage::ConfigImage_Shown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ConfigImage::ConfigImage_MouseMove);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar7))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			CoImage->SetARGB(this->trackBar6->Value,this->trackBar1->Value,this->trackBar2->Value,this->trackBar5->Value);
		}
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			CoImage->SetARGB(this->trackBar6->Value,this->trackBar1->Value,this->trackBar2->Value,this->trackBar5->Value);
		}
private: System::Void trackBar5_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			CoImage->SetARGB(this->trackBar6->Value,this->trackBar1->Value,this->trackBar2->Value,this->trackBar5->Value);
		}
private: System::Void trackBar6_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			CoImage->SetARGB(this->trackBar6->Value,this->trackBar1->Value,this->trackBar2->Value,this->trackBar5->Value);
		}
private: System::Void trackBar7_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			float size = pow((float)this->trackBar7->Value+500,3)/powf(500,3);
			CoImage->SetSize(size,size);
		}
private: System::Void trackBar8_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 float Rot = (float)this->trackBar8->Value/100;
			 CoImage->SetRotation(Rot);


		 }
private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			


		 }
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}

			
		 }
private: System::Void ConfigImage_Load(System::Object^  sender, System::EventArgs^  e) {
			

		 }
private: System::Void ConfigImage_Shown(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void panel2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}
		 }
private: System::Void trackBar7_Scroll(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void trackBar8_Scroll(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if(checkBox1->Checked ==true)
				 CoImage->SetSize(-CoImage->GetSize().x,CoImage->GetSize().y);
			 else
				 CoImage->SetSize(-CoImage->GetSize().x,CoImage->GetSize().y);
		 }
private: System::Void radioButton30_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =6;
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 CoImage->SoursBlend =1;
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =2;
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =3;
		 }
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =4;
		 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =5;
		 }
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =6;
		 }
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =7;
		 }
private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =8;
		 }
private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =9;
		 }
private: System::Void radioButton13_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =10;
		 }
private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =11;
		 }
private: System::Void radioButton15_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =12;
		 }
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =13;
		 }
private: System::Void radioButton14_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->SoursBlend =14;
		 }

private: System::Void radioButton42_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =1;
		 }
private: System::Void radioButton33_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =2;
		 }
private: System::Void radioButton38_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =3;
		 }
private: System::Void radioButton28_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =4;
		 }
private: System::Void radioButton40_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =5;
		 }
private: System::Void radioButton35_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =7;
		 }
private: System::Void radioButton24_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =8;
		 }
private: System::Void radioButton41_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =9;
		 }
private: System::Void radioButton31_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =10;
		 }
private: System::Void radioButton36_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =11;
		 }
private: System::Void radioButton26_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =12;
		 }
private: System::Void radioButton39_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =13;
		 }
private: System::Void radioButton29_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoImage->DestBlend =14;
		 }

private: System::Void tabPage2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}
		 }
private: System::Void tabControl1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}
		 }
private: System::Void tabPage1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}
		 }
private: System::Void ConfigImage_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			 if( e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				GetCursorPos(Pos);
				this->Left  = Loc->x-(LastPos->x -Pos->x);
				this->Top= Loc->y-(LastPos->y -Pos->y);

			}
			else
			{
				GetCursorPos(LastPos);
				Loc->x = this->Left;
				Loc->y = this->Top;
			}
		 }
};
}
