#pragma once
#include "MyForm1.h"

namespace work_with_graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: static Chart^ chart1;
	protected: 
	private: System::Windows::Forms::Button^  button1;

	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(423, 294);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(2, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(441, 49);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�������� �����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 362);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// ��������� ����� ����� � ��������� "Line" (aka ������) �� ��� chart 
		chart1->Series->Add("Line");
		/* 
		 * �������, ��� ����� ����� ������ ������ (� ��� ��� ����� ���� ������� Point, 
		 * ������� ������ Line ��� ������������ (�� �������)) 
		 */
		chart1->Series["Line"]->ChartType = SeriesChartType::Spline;
	}

	// ��� ��� ����� ��������� ������ �����
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// ������� �������� ������ �����
		MyForm1^ form = gcnew MyForm1();

		// ���������� ����������� �������
		form->FormClosing += gcnew FormClosingEventHandler(this, &MyForm::MyForm1_FormClosing);	// ����� ������ �� ����� ���� !!!!!!!!!!
		// ���������� �����
		form->Show();
	}
	
	// ������� ��� ���������� ����� �� ������ �� �����������
	public: static System::Void addPoint(int x, int y) {
		// ������� ��������� ������ ����� � ����� ������������ x � y
		DataPoint^ point1 = gcnew DataPoint(x, y);
		// ��������� ����� � ����� Line
		chart1->Series["Line"]->Points->Add(point1);
	}

	// ���������� �������� ����� 1
	public: System::Void MyForm1_FormClosing(Object^ sender, FormClosingEventArgs^ e) {
		// �������� ���������� �� ������ �����
		int x = ((MyForm1^) sender)->getX();
		int y = ((MyForm1^) sender)->getY();
		// ��������� �����
		addPoint(x, y);
	}
};
}