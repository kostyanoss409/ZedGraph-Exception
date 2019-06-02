#pragma once
#include <cmath>
#include <fstream>
#include <sstream>

namespace VM2 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		double left_border, right_border, step, x, y, Q, w, A;
		unsigned int amount, degree, enter;
		int i, j, k, n, left, middle, right, inter_amount;
		char *buffer;
		PointPairList^ listFile = gcnew PointPairList();
		PointPairList^ listBase = gcnew PointPairList();
		PointPairList^ listLagrange = gcnew PointPairList();
		PointPairList^ listNewton = gcnew PointPairList();
		PointPairList^ Point = gcnew PointPairList();
		MyForm(void)
		{
			InitializeComponent();
			PrepareGraph();
			degree = 0;
			inter_amount = 100;
			n = 0;
		}		
	protected:
		~MyForm(){if (components) { delete components; }}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  AmountOfPoints;
	private: System::Windows::Forms::TextBox^  RightBorder;
	private: System::Windows::Forms::TextBox^  LeftBorder;
	private: System::Windows::Forms::Button^  CoordinatesToFile;
	private: System::Windows::Forms::ComboBox^  InterpolationDegree;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  LagrangeInterpolation;
	private: System::Windows::Forms::Button^  NewtonInterpolation;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  X_value;
	private: System::Windows::Forms::TextBox^  Y_value;
	private: System::Windows::Forms::Label^  label6;
	private: System::ComponentModel::IContainer^  components;
	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AmountOfPoints = (gcnew System::Windows::Forms::TextBox());
			this->RightBorder = (gcnew System::Windows::Forms::TextBox());
			this->LeftBorder = (gcnew System::Windows::Forms::TextBox());
			this->CoordinatesToFile = (gcnew System::Windows::Forms::Button());
			this->InterpolationDegree = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->LagrangeInterpolation = (gcnew System::Windows::Forms::Button());
			this->NewtonInterpolation = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->X_value = (gcnew System::Windows::Forms::TextBox());
			this->Y_value = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->IsEnableHPan = false;
			this->zedGraphControl1->IsEnableHZoom = false;
			this->zedGraphControl1->IsEnableVPan = false;
			this->zedGraphControl1->IsEnableVZoom = false;
			this->zedGraphControl1->IsEnableWheelZoom = false;
			this->zedGraphControl1->Location = System::Drawing::Point(13, 13);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(802, 555);
			this->zedGraphControl1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(822, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(276, 48);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(844, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Левая граница:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(836, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Правая граница:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(822, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Количество точек:";
			// 
			// AmountOfPoints
			// 
			this->AmountOfPoints->Location = System::Drawing::Point(960, 126);
			this->AmountOfPoints->Name = L"AmountOfPoints";
			this->AmountOfPoints->Size = System::Drawing::Size(138, 22);
			this->AmountOfPoints->TabIndex = 3;
			// 
			// RightBorder
			// 
			this->RightBorder->Location = System::Drawing::Point(960, 100);
			this->RightBorder->Name = L"RightBorder";
			this->RightBorder->Size = System::Drawing::Size(138, 22);
			this->RightBorder->TabIndex = 2;
			// 
			// LeftBorder
			// 
			this->LeftBorder->Location = System::Drawing::Point(960, 74);
			this->LeftBorder->Name = L"LeftBorder";
			this->LeftBorder->Size = System::Drawing::Size(138, 22);
			this->LeftBorder->TabIndex = 1;
			// 
			// CoordinatesToFile
			// 
			this->CoordinatesToFile->Location = System::Drawing::Point(822, 163);
			this->CoordinatesToFile->Name = L"CoordinatesToFile";
			this->CoordinatesToFile->Size = System::Drawing::Size(276, 64);
			this->CoordinatesToFile->TabIndex = 4;
			this->CoordinatesToFile->Text = L"Записать в файл";
			this->CoordinatesToFile->UseVisualStyleBackColor = true;
			this->CoordinatesToFile->Click += gcnew System::EventHandler(this, &MyForm::CoordinatesToFile_Click);
			// 
			// InterpolationDegree
			// 
			this->InterpolationDegree->FormattingEnabled = true;
			this->InterpolationDegree->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->InterpolationDegree->Location = System::Drawing::Point(994, 262);
			this->InterpolationDegree->Name = L"InterpolationDegree";
			this->InterpolationDegree->Size = System::Drawing::Size(46, 24);
			this->InterpolationDegree->TabIndex = 5;
			this->InterpolationDegree->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::InterpolationDegree_SelectionChangeCommitted);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(822, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(166, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Степень интерполяции:";
			// 
			// LagrangeInterpolation
			// 
			this->LagrangeInterpolation->Location = System::Drawing::Point(822, 310);
			this->LagrangeInterpolation->Name = L"LagrangeInterpolation";
			this->LagrangeInterpolation->Size = System::Drawing::Size(275, 53);
			this->LagrangeInterpolation->TabIndex = 6;
			this->LagrangeInterpolation->Text = L"Построить график интерполяции по Лагранжу ";
			this->LagrangeInterpolation->UseVisualStyleBackColor = true;
			this->LagrangeInterpolation->Click += gcnew System::EventHandler(this, &MyForm::LagrangeInterpolation_Click);
			// 
			// NewtonInterpolation
			// 
			this->NewtonInterpolation->Location = System::Drawing::Point(822, 385);
			this->NewtonInterpolation->Name = L"NewtonInterpolation";
			this->NewtonInterpolation->Size = System::Drawing::Size(275, 53);
			this->NewtonInterpolation->TabIndex = 7;
			this->NewtonInterpolation->Text = L"Построить график интерполяции по Ньютону";
			this->NewtonInterpolation->UseVisualStyleBackColor = true;
			this->NewtonInterpolation->Click += gcnew System::EventHandler(this, &MyForm::NewtonInterpolation_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(822, 476);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(21, 17);
			this->label5->TabIndex = 16;
			this->label5->Text = L"X:";
			// 
			// X_value
			// 
			this->X_value->Location = System::Drawing::Point(849, 473);
			this->X_value->Name = L"X_value";
			this->X_value->Size = System::Drawing::Size(191, 22);
			this->X_value->TabIndex = 8;
			// 
			// Y_value
			// 
			this->Y_value->Location = System::Drawing::Point(849, 501);
			this->Y_value->Name = L"Y_value";
			this->Y_value->ReadOnly = true;
			this->Y_value->Size = System::Drawing::Size(191, 22);
			this->Y_value->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(822, 504);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 17);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Y:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1110, 581);
			this->Controls->Add(this->Y_value);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->X_value);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->NewtonInterpolation);
			this->Controls->Add(this->LagrangeInterpolation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->InterpolationDegree);
			this->Controls->Add(this->CoordinatesToFile);
			this->Controls->Add(this->LeftBorder);
			this->Controls->Add(this->RightBorder);
			this->Controls->Add(this->AmountOfPoints);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"Интерполяция";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
private: void PrepareGraph()
{
	GraphPane^ myPane = zedGraphControl1->GraphPane;	
	//удаление подписей к графику и осям
	myPane->Title->IsVisible = false;
	myPane->XAxis->Title->IsVisible = false;
	myPane->YAxis->Title->IsVisible = false;
	//авторазмеры осей
	myPane->XAxis->Scale->MinAuto = true;
	myPane->YAxis->Scale->MinAuto = true;
	myPane->XAxis->Scale->MaxAuto = true;
	myPane->YAxis->Scale->MaxAuto = true;
	//удаление меток на противоположных осям сторонах
	myPane->XAxis->MajorTic->IsOpposite = false;
	myPane->XAxis->MinorTic->IsOpposite = false;
	myPane->YAxis->MajorTic->IsOpposite = false;
	myPane->YAxis->MinorTic->IsOpposite = false;
	//сетка
	myPane->XAxis->MajorGrid->IsVisible = true;
	myPane->YAxis->MajorGrid->IsVisible = true;
	//формат чисел на осях
	myPane->XAxis->Scale->Format = "G3";
	myPane->XAxis->Scale->Mag = 0;
	myPane->YAxis->Scale->Format = "G3";
	myPane->YAxis->Scale->Mag = 0;
	//обновление графика
	zedGraphControl1->AxisChange();
	zedGraphControl1->Invalidate();
}
private: int GraphFromFile()
{
	ifstream file("input.txt");
	buffer = new char[100];
	string fileData;
	ostringstream stream;
	stream << file.rdbuf();
	fileData = stream.str();
	if (fileData.size() == 0)
	{MessageBox::Show(this, "Пустой файл", "Ошибка");	return 0;}
	j = 0; n = 0; enter = 0;
	try
	{
		for (i = 0; i < fileData.size(); i++)
		{
			if (fileData[i] >= '0' && fileData[i] <= '9' || fileData[i] == '.' || fileData[i] == 'e' || fileData[i] == 'E' || fileData[i] == '-' || fileData[i] == '+' || fileData[i] == ' ' || fileData[i] == '\n')
			{
				if (fileData[i] != ' ' && fileData[i] != '\n')
				{
					buffer[j] = fileData[i];
					j++;
				}
				else
				{
					if (fileData[i] == '\n')
						enter++;
					n++;
					if (n % 2 == 1)
					{
						x = atof(buffer);
						if (x == INFINITY)
							throw 1;
					}
					else
					{
						y = atof(buffer);
						if (y == INFINITY)
							throw 1;
						listFile->Add(x, y);
					}
					memset(buffer, 0, sizeof(buffer) * 4);
					j = 0;
				}
			}
			else
			{
				MessageBox::Show(this, "Некорректные данные в файле", "Ошибка");
				return 0;
			}
		}
	}
	catch (int a)
	{
		MessageBox::Show(this, "Выход за диапазон допустимых значений в файле", "Ошибка");
		return 0;
	}
	if (n != enter * 2)
	{
		MessageBox::Show(this, "Некорректные данные в файле", "Ошибка");
		return 0;
	}
	GraphPane^ myPane = zedGraphControl1->GraphPane;
	listFile->TrimExcess();
	listFile->Sort();
	myPane->XAxis->Scale->Min = listFile[0]->X;
	myPane->XAxis->Scale->Max = listFile[listFile->Count - 1]->X;
	LineItem ^fileCurve = myPane->AddCurve("Из файла", listFile, Color::Black, SymbolType::None);
	fileCurve->Line->Width = 1;
	zedGraphControl1->AxisChange();
	zedGraphControl1->Invalidate();
	return 1;
}
private: PointPairList^ FindBasePoints(PointPairList^ PointsFromFile, int Degree)
{
	PointPairList^ BasePoints = gcnew PointPairList();
	BasePoints->Add(PointsFromFile[0]->X, PointsFromFile[0]->Y);
	switch (Degree)
	{
	case 2:
	{
		middle = (PointsFromFile->Count - 1) / 2;
		BasePoints->Add(PointsFromFile[middle]->X, PointsFromFile[middle]->Y);
		break;
	}
	case 3:
	{
		left = (PointsFromFile->Count - 1) / 3;
		BasePoints->Add(PointsFromFile[left]->X, PointsFromFile[left]->Y);
		right = (PointsFromFile->Count - 1) * 2 / 3;
		BasePoints->Add(PointsFromFile[right]->X, PointsFromFile[right]->Y);
		break;
	}
	case 4:
	{
		left = (PointsFromFile->Count - 1) / 4;
		BasePoints->Add(PointsFromFile[left]->X, PointsFromFile[left]->Y);
		middle = (PointsFromFile->Count - 1) / 2;
		BasePoints->Add(PointsFromFile[middle]->X, PointsFromFile[middle]->Y);
		right = (PointsFromFile->Count - 1) * 3 / 4;
		BasePoints->Add(PointsFromFile[right]->X, PointsFromFile[right]->Y);
		break;
	}
	default:
		break;
	}
	BasePoints->Add(PointsFromFile[PointsFromFile->Count - 1]->X, PointsFromFile[PointsFromFile->Count - 1]->Y);
	BasePoints->TrimExcess();
	BasePoints->Sort();
	return BasePoints;
}
private: System::Void CoordinatesToFile_Click(System::Object^  sender, System::EventArgs^  e) {
	ofstream file("input.txt");
	try
	{
		left_border = System::Convert::ToDouble(LeftBorder->Text);
		right_border = System::Convert::ToDouble(RightBorder->Text);
		amount = System::Convert::ToUInt64(AmountOfPoints->Text);
	}
	catch (FormatException^ e)
	{
		MessageBox::Show(this, "Некорректный формат ввода", "Ошибка");
		return;
	}
	catch (OverflowException^ e)
	{
		MessageBox::Show(this, "Выход за пределы возможных значений", "Ошибка");
		return;
	}
	if (left_border >= right_border)
	{
		MessageBox::Show(this, "Левая граница должна быть меньше правой", "Ошибка");
		return;
	}
	if (amount < 2)
	{
		MessageBox::Show(this, "Минимум 2 точки", "Ошибка");
		return;
	}
	if (amount > 9000)
	{
		MessageBox::Show(this, "Итс овер найн таузанд", "Ошибка");
		return;
	}
	step = (right_border - left_border) / (amount - 1);
	for (x = left_border; x <= right_border; x += step)
	{
		y = x*x * sin(x) + exp(-x)*cos(x);
		file << x << " " << y << endl;
	}
	MessageBox::Show(this, "Координаты точек записаны в файл", "");
}
private: System::Void InterpolationDegree_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LagrangeInterpolation_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{degree = System::Convert::ToUInt64(InterpolationDegree->Text);}
	catch (OverflowException^ e)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}
	catch (FormatException^ e)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}
	if (degree < 1 || degree > 4)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}	
	GraphPane^ myPane = zedGraphControl1->GraphPane;
	listFile->Clear();
	listBase->Clear();
	listLagrange->Clear();
	myPane->CurveList->Clear();
	if (!GraphFromFile())
		return;
	for (i = 0; i < listFile->Count; i++)
		for (j = i + 1; j < listFile->Count; j++)
			if (listFile[i]->X == listFile[j]->X)
			{
				MessageBox::Show(this, "Для одного значения X присутствует несколько значений Y", "Ошибка");
				return;
			}
	if (n/2 <= degree)
	{
		MessageBox::Show(this, "Степень интерполяции должна быть меньше количества точек", "Ошибка");
		return;
	}
	listBase = FindBasePoints(listFile, degree);
	step = (listBase[listBase->Count - 1]->X - listBase[0]->X) / (inter_amount - 1);
	x = listBase[0]->X;
	for (k = 0; k <= inter_amount; k++)
	{
		y = 0;
		for (i = 0; i <= degree; i++)
		{
			Q = 1;
			for (j = 0; j <= degree; j++)
				if (i != j)
					Q *= (x - listBase[j]->X) / (listBase[i]->X - listBase[j]->X);
			y += listBase[i]->Y * Q;
		}
		listLagrange->Add(x, y);
		x += step;
	}
	LineItem^ LagrangeCurve = myPane->AddCurve("Лагранж", listLagrange, Color::Blue, SymbolType::None);
	LagrangeCurve->Line->Width = 2;
	zedGraphControl1->AxisChange();
	zedGraphControl1->Invalidate();
	if (X_value->Text != "")
	{
		try
		{x = System::Convert::ToDouble(X_value->Text);}
		catch (FormatException^ e)
		{
			MessageBox::Show(this, "Некорректный формат ввода в поле значения X", "Ошибка");
			return;
		}		
		if (x < listFile[0]->X || x > listFile[listFile->Count - 1]->X)
		{
			MessageBox::Show(this, "X вне диапазона", "Ошибка");
			return;
		}
		Point->Clear();
		y = 0;
		for (i = 0; i <= degree; i++)
		{
			Q = 1;
			for (j = 0; j <= degree; j++)
				if (i != j)
					Q *= (x - listBase[j]->X) / (listBase[i]->X - listBase[j]->X);
			y += listBase[i]->Y * Q;
		}
		Point->Add(x, y);
		LineItem^ Star = myPane->AddCurve("", Point, Color::Red, SymbolType::Circle);
		Y_value->Text = Convert::ToString(y);

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}
}
private: System::Void NewtonInterpolation_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{degree = System::Convert::ToUInt64(InterpolationDegree->Text);}
	catch (OverflowException^ e)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}
	catch (FormatException^ e)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}
	if (degree < 1 || degree > 4)
	{
		MessageBox::Show(this, "Степень интерполяции может быть от 1 до 4", "Ошибка");
		return;
	}
	GraphPane^ myPane = zedGraphControl1->GraphPane;
	listFile->Clear();
	listBase->Clear();
	listNewton->Clear();
	myPane->CurveList->Clear();
	if (!GraphFromFile())
		return;
	for (i = 0; i < listFile->Count; i++)
		for (j = i + 1; j < listFile->Count; j++)
				if (listFile[i]->X == listFile[j]->X)
				{
					MessageBox::Show(this, "Для одного значения X присутствует несколько значений Y", "Ошибка");
					return;
				}

	if (n / 2 <= degree)
	{
		MessageBox::Show(this, "Степень интерполяции должна быть меньше количества точек", "Ошибка");
		return;
	}

	listBase = FindBasePoints(listFile, degree);
	step = (listBase[listBase->Count - 1]->X - listBase[0]->X) / (inter_amount - 1);
	x = listBase[0]->X;	
	for (int point = 0; point <= inter_amount; point++)
	{
		y = 0;
		for (i = 0; i <= degree; i++)
		{
			A = 0;
			for (k = 0; k <= i; k++)
			{
				w = 1;
				for (j = 0; j <= i; j++)
					if (j != k)
						w *= listBase[k]->X - listBase[j]->X;
				A += listBase[k]->Y / w;
			}
			for (j = 0; j < i; j++)
				A *= x - listBase[j]->X;
			y += A;
		}
		listNewton->Add(x, y);
		x += step;
	}
	LineItem^ NewtonCurve = myPane->AddCurve("Ньютон", listNewton, Color::Green, SymbolType::None);
	NewtonCurve->Line->Width = 2;
	zedGraphControl1->AxisChange();
	zedGraphControl1->Invalidate();
	if (X_value->Text != "")
	{
		try
		{x = System::Convert::ToDouble(X_value->Text);}
		catch (FormatException^ e)
		{
			MessageBox::Show(this, "Некорректный формат ввода в поле значения X", "Ошибка");
			return;
		}

		if (x < listFile[0]->X || x > listFile[listFile->Count - 1]->X)
		{
			MessageBox::Show(this, "X вне диапазона", "Ошибка");
			return;
		}
		Point->Clear();
		y = 0;
		for (i = 0; i <= degree; i++)
		{
			A = 0;
			for (k = 0; k <= i; k++)
			{
				w = 1;
				for (j = 0; j <= i; j++)
					if (j != k)
						w *= listBase[k]->X - listBase[j]->X;
				A += listBase[k]->Y / w;
			}
			for (j = 0; j < i; j++)
				A *= x - listBase[j]->X;
			y += A;
		}
		Point->Add(x, y);
		LineItem^ Star = myPane->AddCurve("", Point, Color::Red, SymbolType::Circle);
		Y_value->Text = Convert::ToString(y);
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}
}
};
}
