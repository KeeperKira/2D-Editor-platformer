#pragma once


using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RedactorLeve01 {

	/// <summary>
	/// Summary for Layers
		extern DIRECTX	*Direct;
		extern int STATUS;
		extern DECOR	*MyCursor;



	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Objects : public System::Windows::Forms::Form
	{
	public:
		Objects(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
	public:	vector<DECOR>	*Res;


		/// Clean up any resources being used.
		/// </summary>
		~Objects()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::HScrollBar^  hScrollBar1;
	public: System::Windows::Forms::Panel^  panel1;
	protected: 

	protected: 


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
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Cursor = System::Windows::Forms::Cursors::Default;
			this->hScrollBar1->LargeChange = 1;
			this->hScrollBar1->Location = System::Drawing::Point(9, 154);
			this->hScrollBar1->Maximum = 0;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(752, 22);
			this->hScrollBar1->TabIndex = 0;
			this->hScrollBar1->ValueChanged += gcnew System::EventHandler(this, &Objects::hScrollBar1_ValueChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 150);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Objects::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Objects::panel1_MouseClick);
			// 
			// Objects
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(804, 177);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->hScrollBar1);
			this->Location = System::Drawing::Point(200, 800);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(820, 215);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(820, 215);
			this->Name = L"Objects";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Îáúåêò";
			this->Load += gcnew System::EventHandler(this, &Objects::Layers_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			 {
				RECT	Rect;
				Rect.top = 0;
				Rect.left = 0;
					
				Rect.bottom = 150;
				Rect.right = 800;
				

				Direct->pDevice->BeginScene();
				Direct->pDevice->Clear( 0,0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10,10,10), 1.0f, 0 );

				for(int i = 0;i<(int)Res->size();i++)
				{
					Res[0][i].Draw();
				}


				Direct->pDevice->EndScene();
				Direct->pDevice->Present(&Rect,&Rect,(HWND)this->panel1->Handle.ToPointer(),0);


			 }
	private: System::Void Layers_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				Res	=	new	vector<DECOR>;
				
				wifstream fis(L"resource.txt");
				if(!fis.good())
				{
					for(;;);
				}
				DECOR	Imag;
				

				while(!fis.eof())
				{
					static int i=0;
					wchar_t	str1[1000];
					fis>>str1;

					wstring str(str1);

					Imag.LoadImageFromFile(str.c_str());

					Imag.Type = i;
					Res->push_back(Imag);
					this->hScrollBar1->Maximum +=150;

					i++;

				}

				for(int i = 0;i<(int)Res->size();i++)
				{
					Res[0][i].SetPosition(-this->hScrollBar1->Value+i*150.0f,0);
					Res[0][i].SetSize(150/(float)Res[0][i].Width,150/(float)Res[0][i].Height);
	
				}

			}
private: System::Void hScrollBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		//	for(int i = 0;i<(int)Res->size();i++)
			{
			
			}

			RECT	Rect;
			Rect.top = 0;
			Rect.left = 0;
				
			Rect.bottom = 150;
			Rect.right = 800;
			

			Direct->pDevice->BeginScene();
			Direct->pDevice->Clear( 0,0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(10,10,10), 1.0f, 0 );

			for(int i = 0;i<(int)Res->size();i++)
			{
				Res[0][i].SetPosition(-this->hScrollBar1->Value+i*150.0f,0);

				Res[0][i].Draw();
			}


			Direct->pDevice->EndScene();
			Direct->pDevice->Present(&Rect,&Rect,(HWND)this->panel1->Handle.ToPointer(),0);


		 }
private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 STATUS = 1;
			 if(e->Button == System::Windows::Forms::MouseButtons::Left)
			 {
				POINT	Point;
				GetCursorPos(&Point);
				ScreenToClient((HWND)this->panel1->Handle.ToPointer(),&Point);

				for(int i = 0;i<(int)Res->size();i++)
				{
					if(Res[0][i].PointCollide(Point))
						(*MyCursor) = (Res[0][i]);
					MyCursor->SetSize(1.0f,1.0f);
					MyCursor->SetPosition(0.0f,0.0f);
				}
			 }
		 }
};
}
