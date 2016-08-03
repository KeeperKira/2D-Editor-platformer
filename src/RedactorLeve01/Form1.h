#pragma once
#define LAYERS 9

namespace RedactorLeve01 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Form1
			DIRECTX			*Direct;
			int				STATUS;
			DECOR			*MyCursor;
			D3DXVECTOR2		Offset;
			vector<DECOR>	Layers[LAYERS];
			int		CurentLayer;
			bool	VisibleLayers[LAYERS];
			float	SpeedConf[LAYERS];




	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();


			//
			//TODO: Add the constructor code here
			//

			Direct	= new	DIRECTX();
			Direct->Width	=1280;
			Direct->Height	=720;
			Direct->Create((HWND)this->Handle.ToPointer());
			Direct->LookCreate(1280,720);

			MyCursor	=	new	DECOR;

			LayerW	=	gcnew	Objects();
			LayerW->Owner	= this;
			LayerW->Visible = true;

			ConfIm	=	gcnew	ConfigImage();
			ConfIm->Owner	=	this;
			ConfIm->Visible =	true;

			OLayer	=	gcnew	OptLayers();
			OLayer->Owner	=	this;
			OLayer->Visible =	true;
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		
		Objects			^LayerW;
		ConfigImage		^ConfIm;
		OptLayers		^OLayer;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::ToolStripMenuItem^  importToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;









	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;


	protected: 


		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected: 
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->importToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"noname";
			this->saveFileDialog1->Filter = L"Level |*.lev";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1280, 720);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			this->panel1->MouseEnter += gcnew System::EventHandler(this, &Form1::panel1_MouseEnter);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseMove);
			this->panel1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Form1::panel1_PreviewKeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->newToolStripButton, 
				this->openToolStripButton, this->saveToolStripButton, this->toolStripSeparator2, this->toolStripButton1, this->toolStripButton2, 
				this->toolStripButton3});
			this->toolStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->toolStrip1->Size = System::Drawing::Size(1280, 23);
			this->toolStrip1->Stretch = true;
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// newToolStripButton
			// 
			this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripButton.Image")));
			this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripButton->Name = L"newToolStripButton";
			this->newToolStripButton->Size = System::Drawing::Size(23, 20);
			this->newToolStripButton->Text = L"&New";
			this->newToolStripButton->Click += gcnew System::EventHandler(this, &Form1::newToolStripButton_Click);
			// 
			// openToolStripButton
			// 
			this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripButton.Image")));
			this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripButton->Name = L"openToolStripButton";
			this->openToolStripButton->Size = System::Drawing::Size(23, 20);
			this->openToolStripButton->Text = L"&Open";
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(23, 20);
			this->saveToolStripButton->Text = L"&Save";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 23);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 20);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 20);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 20);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1280, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->loadToolStripMenuItem, 
				this->saveToolStripMenuItem, this->toolStripSeparator1, this->importToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(119, 6);
			// 
			// importToolStripMenuItem
			// 
			this->importToolStripMenuItem->Name = L"importToolStripMenuItem";
			this->importToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->importToolStripMenuItem->Text = L"Import ...";
			this->importToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::importToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 747);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->MouseEnter += gcnew System::EventHandler(this, &Form1::Form1_MouseEnter);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {


				 ifstream ifs("conf.txt");
				 
				 if(ifs.good())
				 {
					 label1->Text ="123";
					 for(int in = 0 ;in<LAYERS;in++)
					 {
						 ifs>>SpeedConf[in];
						// ifs.read((char*) &SpeedConf[in],sizeof(int));
					 }
				 }

				CurentLayer = 0;
			 }
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
			 {
				static MSG msg;
				ZeroMemory(&msg,sizeof(msg));
				RECT	Rect;
				Rect.bottom = 720;
				Rect.left = 0;
				Rect.right = 1280;
				Rect.top = 0;

				POINT	Pos;	


				while (msg.message!=WM_QUIT)
				{
					if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);			
					}
					else				
					{
						GetCursorPos(&Pos);
						ScreenToClient((HWND)this->panel1->Handle.ToPointer(),&Pos);

						Direct->pDevice->BeginScene();
						Direct->pDevice->Clear( 0,0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10,10,150), 1.0f, 0 );
						
						float x1,y1,Rot,x2,y2;
						Rot = MyCursor->GetRotation();

						this->label1->Text = MyCursor->GetPosition().x.ToString();

						x1 = (MyCursor->Width*MyCursor->GetSize().x)/2;
						y1 = (MyCursor->Height*MyCursor->GetSize().y)/2;

						x2 = x1*cos(Rot)-y1*sin(Rot);
						y2 = y1*cos(Rot)+x1*sin(Rot);



						MyCursor->SetPosition(Pos.x-x2,Pos.y-y2);
						for(int j = 0;j<9;j++)
						{
							if(VisibleLayers[j]) 
							for(int i = 0;i<(int)Layers[j].size();i++)
								Layers[j][i].Draw();
							if(j == CurentLayer)
							{
								if(STATUS == 1)
								MyCursor->Draw();
							}
						}

						Direct->pDevice->EndScene();
						Direct->pDevice->Present(&Rect,&Rect,(HWND)this->panel1->Handle.ToPointer(),0);
					}
				}

			 }
	private: System::Void Form1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 this->Focus();
			 }
private: System::Void panel1_MouseEnter(System::Object^  sender, System::EventArgs^  e) 
		 {
			MyCursor->SetARGB(this->ConfIm->CoImage->GetAlpha(),this->ConfIm->CoImage->GetRed(),this->ConfIm->CoImage->GetGreen(),this->ConfIm->CoImage->GetBlue());
			this->Focus();
			MyCursor->SetSize(this->ConfIm->CoImage->GetSize().x,this->ConfIm->CoImage->GetSize().y);
			MyCursor->SetRotation(this->ConfIm->CoImage->GetRotation());
			MyCursor->SoursBlend=this->ConfIm->CoImage->SoursBlend;
			MyCursor->DestBlend=this->ConfIm->CoImage->DestBlend;
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			static POINT	Pos;	

			if(e->Button ==System::Windows::Forms::MouseButtons::Left)
			{
				 if(STATUS == 1)
				 {
					 Layers[CurentLayer].push_back(*MyCursor);
				 }

				 if(STATUS == 2)
				 {
				 }
			}


			 if((e->Button == System::Windows::Forms::MouseButtons::Right ) | (e->Button == System::Windows::Forms::MouseButtons::XButton1))
				 
			 {
				GetCursorPos(&Pos);
				ScreenToClient((HWND)this->panel1->Handle.ToPointer(),&Pos);

				for(int i = Layers[CurentLayer].size()-1; i>=0;i--)
				{
					if(Layers[CurentLayer][i].PointCollide(Pos))
					{
						Layers[CurentLayer].erase(Layers[CurentLayer].begin()+i);
						break;
					}
				}
			 }
		 }
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				if(openFileDialog1->ShowDialog() ==System::Windows::Forms::DialogResult::OK)
				{

					marshal_context ^ context = gcnew marshal_context();
					const wchar_t* savefile = context->marshal_as<const wchar_t*>(openFileDialog1->FileName);

					wstring wstr(savefile);
					for(int i = 0 ;i<(int)wstr.size();i++)
					{
						wchar_t g = '\\';
						if(wstr[i] == g)
						{
							wstr.insert(i,1,'\\');
							i++;
						}
					}

					String ^xx = gcnew String(wstr.c_str());
					label1->Text = xx;


						
					ifstream ifs(wstr.c_str(),ios::binary);
					if(!ifs)
					{

						return ;
					}
					int VERSION;
					//Данные о версии;
					ifs.read((char*)&VERSION,sizeof(int));




					if(VERSION == 100)
					{
						//Данные о количестве слоёв
						int Layer;
						ifs.read((char*) &Layer,sizeof(int));



						//данные о количестве объектов в каждом слое
						int *Count = new int[Layer];

						for(int i =0 ;i <Layer;i++)
							Count[i] = 0;

						int suum = 0;

						for(int j = 0 ;j<Layer;j++)
						{
							ifs.read((char*) &(Count[j]),sizeof(int));
							suum+=Count[j];
						}


						//Загрузка данных объекта

						for(int j = 0 ;j<Layer;j++)
						{
							Layers[j].clear();
						}
							
						for(int j = 0 ;j<Layer;j++)
						{
							for(int i = 0 ;i<Count[j];i++)
							{
								DECOR	load;

								int Type;
								ifs.read((char*) &Type,sizeof(int));

								load = this->LayerW->Res[0][Type];

								D3DXVECTOR2 Position;
								ifs.read((char*) &Position.x,sizeof(float));
								ifs.read((char*) &Position.y,sizeof(float));
								load.SetPosition(Position);
								

								D3DXVECTOR2 Size;
								ifs.read((char*) &(Size.x),sizeof(float));
								ifs.read((char*) &(Size.y),sizeof(float));
								load.SetSize(Size.x,Size.y);

								PIXEL	Pix;


								ifs.read((char*) &Pix,sizeof(Pix));

								load.SetARGB(Pix.Alpha,Pix.Red,Pix.Green,Pix.Blue);

								float rot;
								ifs.read((char*) &(rot),sizeof(float));
								load.SetRotation(rot);

								
			
								Layers[j].push_back(load);
			
							}					
						}
					}


					ifs.close();


					delete context;
				}
		}
private: System::Void importToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				DECOR	load;

				marshal_context ^ context = gcnew marshal_context();
				const wchar_t* str4 = context->marshal_as<const wchar_t*>(openFileDialog1->FileName);
				label1->Text = openFileDialog1->FileName;

				wstring wstr(str4);

				int si = wstr.rfind(L'\\');
				wstr.erase(0,si+1);
		//		wstr.push_back(L'd');
				String ^xx = gcnew String(wstr.c_str());
				label1->Text = xx;

				wstring wstr1(L"Texture/");
				wstr1 += wstr;

				CopyFile(str4,wstr1.c_str(),true);



				wofstream ofs("resource.txt",ios::app);
				wstr1.insert(0,1,'\n');

				ofs<<wstr1.c_str();

				load.LoadImageFromFile(str4);

				int i = (int) LayerW->Res->size();

				load.SetSize(150/(float)load.Width,150/(float)load.Height);
				load.SetPosition(i*150.0f,0);
				load.Type = i++;

				this->LayerW->Res->push_back(load);

				this->LayerW->hScrollBar1->Maximum +=150;

				delete context;
				
			}
		 }
private: System::Void toolStripContainer1_LeftToolStripPanel_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(saveFileDialog1->ShowDialog() ==System::Windows::Forms::DialogResult::OK)
			 {

				int VERSION = 100;

				marshal_context ^ context = gcnew marshal_context();
				const wchar_t* savefile = context->marshal_as<const wchar_t*>(saveFileDialog1->FileName);

				wstring wstr(savefile);
				for(int i = 0 ;i<(int)wstr.size();i++)
				{
					wchar_t g = '\\';
					if(wstr[i] == g)
					{
						wstr.insert(i,1,'\\');
						i++;
					}
				}
/*
				String ^xx = gcnew String(wstr.c_str());

				label1->Text = xx;
*/
				
				ofstream ofs(wstr.c_str(),ios::binary);
				if(!ofs)
				{
					label1->Text = L"Gbh";
				}

				//Данные о версии;
				ofs.write((char*)&VERSION,sizeof(int));

				//Данные о количестве слоёв
				int Layer = 9;
				ofs.write((char*) &Layer,sizeof(int));

				//данные о количестве объектов в каждом слое

				for(int j = 0 ;j<9;j++)
				{
					int count = (int)Layers[j].size();
					ofs.write((char*) &count,sizeof(int));
				}
				
				for(int j = 0 ;j<9;j++)
				{
					for(int i = 0 ;i<(int)Layers[j].size();i++)
					{
						
						ofs.write((char*) &Layers[j][i].Type,sizeof(int));

						ofs.write((char*) &Layers[j][i].Position.x,sizeof(float));
						ofs.write((char*) &Layers[j][i].Position.y,sizeof(float));

						float six,siy;
						six =Layers[j][i].GetSize().x;
						siy =Layers[j][i].GetSize().y;

						ofs.write((char*)(&six),sizeof(float));
						ofs.write((char*)(&siy),sizeof(float));

						PIXEL	Pix;
						Pix.Alpha = Layers[j][i].GetAlpha();
						Pix.Red = Layers[j][i].GetRed();
						Pix.Green = Layers[j][i].GetGreen();
						Pix.Blue = Layers[j][i].GetBlue();

						ofs.write((char*) &Pix,sizeof(Pix));
						float rot = Layers[j][i].GetRotation();
						ofs.write((char*) &(rot),sizeof(float));


					}					
				}

				ofs.close();

				delete context;
			 }

		 }
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 STATUS = 2;
		 }
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 STATUS = 1;
		 }
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 static POINT	Pos,LastPos,Ofs;	

			 GetCursorPos(&Pos);

			if(e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				 
				 Ofs.x = (LastPos.x-Pos.x);
				 Ofs.y = (LastPos.y-Pos.y);

				 if(STATUS == 2)
				 {
					for(int j = 0;j<9;j++)
					{
						D3DXVECTOR2 Offset;
						Offset.x=Ofs.x*SpeedConf[j];
						Offset.y=Ofs.y*SpeedConf[j];

						for(int i = 0;i<(int)Layers[j].size();i++)
						{
							Layers[j][i].Move(Offset);

							//Layers[j][i].SetPosition(Layers[j][i].GetPosition().x-Ofs.x,Layers[j][i].GetPosition().y-Ofs.y);
						}
					}
				 }				
			}

			LastPos = Pos;
				// Offset.x -= Ofs.x;
				// Offset.y -= Ofs.y;
		 }
private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

		 }
private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			static POINT	Ofs;	

			if(e->KeyValue == 37)
			{			 
				
				Ofs.y = 0;
				for(int j = 0;j<9;j++)
				{
					Ofs.x = (LONG)SpeedConf[j];
					for(int i = 0;i<(int)Layers[j].size();i++)
					{
						Layers[j][i].SetPosition(Layers[j][i].GetPosition().x-Ofs.x,Layers[j][i].GetPosition().y-Ofs.y);
					}
				}				
			}

			if(e->KeyValue == 39)
			{			 
				
				Ofs.y = 0;
				for(int j = 0;j<9;j++)
				{
					Ofs.x = -(LONG)SpeedConf[j];
					for(int i = 0;i<(int)Layers[j].size();i++)
					{
						Layers[j][i].SetPosition(Layers[j][i].GetPosition().x-Ofs.x,Layers[j][i].GetPosition().y-Ofs.y);
					}
				}				
			}

			if(e->KeyValue == 38)
			{			 
				Ofs.x = 0;
				
				for(int j = 0;j<9;j++)
				{
					Ofs.y = (LONG)SpeedConf[j];
					for(int i = 0;i<(int)Layers[j].size();i++)
					{
						Layers[j][i].SetPosition(Layers[j][i].GetPosition().x-Ofs.x,Layers[j][i].GetPosition().y-Ofs.y);
					}
				}				
			}

			if(e->KeyValue == 40)
			{			 
				Ofs.x = 0;
				
				for(int j = 0;j<9;j++)
				{
					Ofs.y = -(LONG)SpeedConf[j];
					for(int i = 0;i<(int)Layers[j].size();i++)
					{
						Layers[j][i].SetPosition(Layers[j][i].GetPosition().x-Ofs.x,Layers[j][i].GetPosition().y-Ofs.y);
					}
				}				
			}


		 }
private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {


		 }
private: System::Void newToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) {


		//	MessageBoxButtons buttons=MessageBoxButtonsButtons::YesNo;
			System::Windows::Forms::DialogResult result;
	//		System::Windows::Forms::DialogResult result = 
			result = MessageBox::Show( "Не сохраненные даные будут удалены", "Внимание!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning );

			if(result==::DialogResult::Yes)
			{
				for(int i = 0;i<LAYERS;i++)
				{
				Layers[i].clear();
				}
			}

			if(result==::DialogResult::No){
				////
			}


		 }
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
			 STATUS = 3;
		 }
};
}

