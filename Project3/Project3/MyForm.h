#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			A1 = 3;
			textBox_a1->Text = Convert::ToString(A1);
			A2 = 5;
			textBox_a1->Text = Convert::ToString(A2);
			A3 = 10;
			textBox_a1->Text = Convert::ToString(A3);
			F1 = 5;
			textBox_a1->Text = Convert::ToString(F1);
			F2 = 10;
			textBox_a1->Text = Convert::ToString(F2);
			F3 = 3;
			textBox_a1->Text = Convert::ToString(F3);
			Y1 = 0;
			textBox_a1->Text = Convert::ToString(Y1);
			Y2 = 3;
			textBox_a1->Text = Convert::ToString(Y2);
			Y3 = 0;
			textBox_a1->Text = Convert::ToString(Y3);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ start_butt;
	protected:
	private: System::Windows::Forms::TextBox^ textBox_a1;
	private: System::Windows::Forms::TextBox^ textBox_f1;
	private: System::Windows::Forms::TextBox^ textBox_y1;
	private: System::Windows::Forms::TextBox^ textBox_a2;
	private: System::Windows::Forms::TextBox^ textBox_f2;
	private: System::Windows::Forms::TextBox^ textBox_y2;
	private: System::Windows::Forms::TextBox^ textBox_a3;
	private: System::Windows::Forms::TextBox^ textBox_f3;
	private: System::Windows::Forms::TextBox^ textBox_y3;
	private: System::Windows::Forms::TextBox^ textBox_fd;
	private: System::Windows::Forms::TextBox^ textBox_n;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label9;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->start_butt = (gcnew System::Windows::Forms::Button());
			this->textBox_a1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_f1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_a2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_f2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_a3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_f3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_fd = (gcnew System::Windows::Forms::TextBox());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->SuspendLayout();
			// 
			// start_butt
			// 
			this->start_butt->Location = System::Drawing::Point(102, 436);
			this->start_butt->Name = L"start_butt";
			this->start_butt->Size = System::Drawing::Size(166, 86);
			this->start_butt->TabIndex = 0;
			this->start_butt->Text = L"start";
			this->start_butt->UseVisualStyleBackColor = true;
			this->start_butt->Click += gcnew System::EventHandler(this, &MyForm::start_butt_Click);
			// 
			// textBox_a1
			// 
			this->textBox_a1->Location = System::Drawing::Point(43, 53);
			this->textBox_a1->Name = L"textBox_a1";
			this->textBox_a1->Size = System::Drawing::Size(87, 20);
			this->textBox_a1->TabIndex = 1;
			// 
			// textBox_f1
			// 
			this->textBox_f1->Location = System::Drawing::Point(136, 53);
			this->textBox_f1->Name = L"textBox_f1";
			this->textBox_f1->Size = System::Drawing::Size(80, 20);
			this->textBox_f1->TabIndex = 2;
			// 
			// textBox_y1
			// 
			this->textBox_y1->Location = System::Drawing::Point(222, 53);
			this->textBox_y1->Name = L"textBox_y1";
			this->textBox_y1->Size = System::Drawing::Size(82, 20);
			this->textBox_y1->TabIndex = 3;
			// 
			// textBox_a2
			// 
			this->textBox_a2->Location = System::Drawing::Point(43, 95);
			this->textBox_a2->Name = L"textBox_a2";
			this->textBox_a2->Size = System::Drawing::Size(87, 20);
			this->textBox_a2->TabIndex = 4;
			// 
			// textBox_f2
			// 
			this->textBox_f2->Location = System::Drawing::Point(136, 95);
			this->textBox_f2->Name = L"textBox_f2";
			this->textBox_f2->Size = System::Drawing::Size(80, 20);
			this->textBox_f2->TabIndex = 5;
			// 
			// textBox_y2
			// 
			this->textBox_y2->Location = System::Drawing::Point(222, 95);
			this->textBox_y2->Name = L"textBox_y2";
			this->textBox_y2->Size = System::Drawing::Size(82, 20);
			this->textBox_y2->TabIndex = 6;
			// 
			// textBox_a3
			// 
			this->textBox_a3->Location = System::Drawing::Point(43, 134);
			this->textBox_a3->Name = L"textBox_a3";
			this->textBox_a3->Size = System::Drawing::Size(87, 20);
			this->textBox_a3->TabIndex = 7;
			// 
			// textBox_f3
			// 
			this->textBox_f3->Location = System::Drawing::Point(136, 134);
			this->textBox_f3->Name = L"textBox_f3";
			this->textBox_f3->Size = System::Drawing::Size(80, 20);
			this->textBox_f3->TabIndex = 8;
			// 
			// textBox_y3
			// 
			this->textBox_y3->Location = System::Drawing::Point(222, 134);
			this->textBox_y3->Name = L"textBox_y3";
			this->textBox_y3->Size = System::Drawing::Size(82, 20);
			this->textBox_y3->TabIndex = 9;
			// 
			// textBox_fd
			// 
			this->textBox_fd->Location = System::Drawing::Point(43, 189);
			this->textBox_fd->Name = L"textBox_fd";
			this->textBox_fd->Size = System::Drawing::Size(87, 20);
			this->textBox_fd->TabIndex = 10;
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(136, 189);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(80, 20);
			this->textBox_n->TabIndex = 11;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(391, 53);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(438, 131);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(391, 204);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Series2";
			this->chart2->Series->Add(series2);
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(438, 141);
			this->chart2->TabIndex = 13;
			this->chart2->Text = L"chart2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"A";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(166, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"F";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(255, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 53);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 95);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(80, 171);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"fd";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(166, 173);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(15, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"N";
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(391, 367);
			this->chart3->Name = L"chart3";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Legend = L"Legend1";
			series5->Name = L"Series2";
			this->chart3->Series->Add(series4);
			this->chart3->Series->Add(series5);
			this->chart3->Size = System::Drawing::Size(438, 155);
			this->chart3->TabIndex = 22;
			this->chart3->Text = L"chart3";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(222, 189);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(82, 20);
			this->textBox1->TabIndex = 23;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(255, 174);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"γ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 604);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox_n);
			this->Controls->Add(this->textBox_fd);
			this->Controls->Add(this->textBox_y3);
			this->Controls->Add(this->textBox_f3);
			this->Controls->Add(this->textBox_a3);
			this->Controls->Add(this->textBox_y2);
			this->Controls->Add(this->textBox_f2);
			this->Controls->Add(this->textBox_a2);
			this->Controls->Add(this->textBox_y1);
			this->Controls->Add(this->textBox_f1);
			this->Controls->Add(this->textBox_a1);
			this->Controls->Add(this->start_butt);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: double a, b;
	private: double t, y1, y2, y3;
	private: double A1, F1, Y1;
	private: double A2, F2, Y2;
	private: double A3, F3, Y3;
	private: int N;
	private: double fd;
	private: System::Void start_butt_Click(System::Object^ sender, System::EventArgs^ e);
    private: void DefaultParams();

};
}
