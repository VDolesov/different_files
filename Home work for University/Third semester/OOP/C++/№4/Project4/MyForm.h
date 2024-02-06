#pragma once

namespace Project4 {

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
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(61, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Цех-ТО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(279, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Цех-Кузовной ремонт";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(568, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Цех-Шиномонтаж";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(806, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(130, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Цех-Ремонт Двигателя";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(859, 483);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 86);
			this->button1->TabIndex = 4;
			this->button1->Text = L"ШАГ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->textBox1->Location = System::Drawing::Point(22, 85);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(198, 141);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(263, 85);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(198, 141);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(506, 85);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(211, 141);
			this->textBox3->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(753, 85);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox4->Size = System::Drawing::Size(235, 141);
			this->textBox4->TabIndex = 8;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(22, 260);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(173, 194);
			this->textBox5->TabIndex = 9;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(282, 260);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(169, 194);
			this->textBox6->TabIndex = 10;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(536, 253);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(162, 201);
			this->textBox7->TabIndex = 11;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(796, 253);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(160, 192);
			this->textBox8->TabIndex = 12;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(536, 499);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(181, 70);
			this->textBox9->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label5->Location = System::Drawing::Point(599, 464);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"ВРЕМЯ";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(463, 226);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Очереди";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 645);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		kk++;

		if (kk == 1)
		{
			tm date;
			localtime_s(&date, &time_now);
			if (date.tm_wday != 0) {
				time_now = time_now - date.tm_sec - date.tm_min * 60 - date.tm_hour * 60 * 60 - (date.tm_wday - 1) * 24 * 60 * 60 + 28800;

			}
			else
			{
				time_now = time_now - date.tm_sec - date.tm_min * 60 - date.tm_hour * 60 * 60 - 6 * 24 * 60 * 60 + 28800;

			}
			time_end = time_now + 12 * 60 * 60;
		}
		tm dt;
		localtime_s(&dt, &time_now);
		if (dt.tm_hour == 20 && dt.tm_min == 30 && dt.tm_wday != 6 && dt.tm_wday != 5) // переопределяем время для след дней
		{
			time_now += 11 * 60 * 60 + 30 * 60;

			//tm mp;
			//localtime_s(&dt, &time_now);

			time_end = time_now + 12 * 60 * 60;

			mas11 = NULL;
			mas12 = NULL;
			mas21 = NULL;
			mas22 = NULL;
			mas31 = NULL;
			mas32 = NULL;
			mas41 = NULL;
			mas42 = NULL;

		}

		if (dt.tm_wday == 5 && dt.tm_hour == 20 && dt.tm_min == 30)
		{
			time_now += 11 * 60 * 60 + 30 * 60;
			time_end = time_now + 8 * 60 * 60;

			mas11 = NULL;
			mas12 = NULL;
			mas21 = NULL;
			mas22 = NULL;
			mas31 = NULL;
			mas32 = NULL;
			mas41 = NULL;
			mas42 = NULL;
		}

		if (dt.tm_wday == 6 && dt.tm_hour == 16 && dt.tm_min == 30)
		{
			time_now += 15 * 60 * 60 + 30 * 60;
			time_end = time_now + 8 * 60 * 60;
			mas11 = NULL;
			mas12 = NULL;
			mas21 = NULL;
			mas22 = NULL;
			mas31 = NULL;
			mas32 = NULL;
			mas41 = NULL;
			mas42 = NULL;
		}



		if ((dt.tm_hour == 19 && dt.tm_min == 30 && dt.tm_wday != 6) || (dt.tm_hour == 15 && dt.tm_min == 30 && dt.tm_wday == 6))
		{
			del_all(); // очередь уходит
		}


		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";
		textBox7->Text = "";
		textBox8->Text = "";

		
		


		if (dt.tm_hour == 20 && dt.tm_min == 0)
		{
			
			total();


			auto suma_1 = pr11 + pr12;
			auto suma_2 = pr21 + pr22;
			auto suma_3 = pr31 + pr32;
			auto suma_4 = pr41 + pr42;

			int suma_11, suma_12, suma_21, suma_22, suma_31, suma_32, suma_41, suma_42;
			this->textBox5->Text += Environment::NewLine + " всего было  услуг " + System::Convert::ToString(counter1);

			this->textBox8->Text += Environment::NewLine + " всего было  машин " + System::Convert::ToString(((cars11.getCount() + cars12.getCount()) + (cars21.getCount() + cars22.getCount()) + (cars31.getCount() + cars32.getCount()) + (cars41.getCount() + cars42.getCount())));
			
			this->textBox7->Text += Environment::NewLine + " среднее время обслуживание одной машины в минутах " + System::Convert::ToString( counter2/60/((cars11.getCount()+ cars12.getCount())+ (cars21.getCount() + cars22.getCount()) + (cars31.getCount() + cars32.getCount() )+ (cars41.getCount() + cars42.getCount()))+2);

			this->textBox1->Text+=Environment::NewLine+" 1 мастер 1 цеха сумма: "+System::Convert::ToString(pr11) + " кол во автомобилей: " + System::Convert::ToString(cars11.getCount());
			this->textBox1->Text += Environment::NewLine + " 2 мастер 1 цеха сумма: " + System::Convert::ToString(pr12) + " кол во автомобилей: " + System::Convert::ToString(cars12.getCount());

			this->textBox1->Text += Environment::NewLine + "Общая выручка : " + System::Convert::ToString(pr12+pr11) + " прибль " + System::Convert::ToString(pr11*0.75+pr12*0.75);

			if (pr11 > pr12) {
				this->textBox1->Text += Environment::NewLine + " Первый мастер сделал выручку выше чем второй на : " + System::Convert::ToString(pr11 - pr12);
			}

			if (pr12 > pr11) {
				this->textBox1->Text += Environment::NewLine + " Второй мастер сделал выручку выше чем первый на : " + System::Convert::ToString(pr12 - pr11);
			}
			
			if (pr11 * 0.25 >= 1000) {

				suma_11 += pr11*0.25;
				//(mas11->GetTime()
			}
			else if (pr11*0.25<1000){
				suma_11 += 1000;
			}
			this->textBox1->Text += Environment::NewLine + "Зп 1 мастера : " + System::Convert::ToString(suma_11);

			if (chet != 6) {
				zp_11 += suma_11;
			}
			chet++;
			this->textBox1->Text += Environment::NewLine + "средняя Зп 1 мастера : " + System::Convert::ToString(zp_11/chet);

			if (pr12 * 0.25 >= 1000) {

				suma_12+= pr12 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr12 * 0.25 < 1000) {
				suma_12 += 1000;
			}
			this->textBox1->Text += Environment::NewLine + "Зп 2 мастера : " + System::Convert::ToString(suma_12);
			
			if (chet != 6) {
				zp_12 += suma_12;
			}
			chet++;
			this->textBox1->Text += Environment::NewLine + "средняя Зп 2 мастера : " + System::Convert::ToString(zp_12 / chet);


			this->textBox2->Text += Environment::NewLine + " 1 мастер 2 цеха сумма: " + System::Convert::ToString(pr21) + " кол во автомобилей: " + System::Convert::ToString(cars21.getCount());
			this->textBox2->Text += Environment::NewLine + " 2 мастер 2 цеха сумма: " + System::Convert::ToString(pr22) + " кол во автомобилей: " + System::Convert::ToString(cars22.getCount());

			this->textBox2->Text += Environment::NewLine + "Общая выручка : " + System::Convert::ToString(pr22 + pr21) + " прибль " + System::Convert::ToString(pr21 * 0.75 + pr22 * 0.75);

			if (pr21 > pr22) {
				this->textBox2->Text += Environment::NewLine + " Первый мастер сделал выручку выше чем второй на : " + System::Convert::ToString(pr21 - pr22);
			}

			if (pr22 > pr21) {
				this->textBox2->Text += Environment::NewLine + " Второй мастер сделал выручку выше чем первый на : " + System::Convert::ToString(pr22 - pr21);
			}


			if (pr21 * 0.25 >= 1000) {

				suma_21 += pr11 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr21 * 0.25 < 1000) {
				suma_21 += 1000;
			}
			this->textBox2->Text += Environment::NewLine + "Зп 1 мастера : " + System::Convert::ToString(suma_21);

			if (chet != 6) {
				zp_21 += suma_21;
			}
			chet++;
			this->textBox2->Text += Environment::NewLine + "средняя Зп 1 мастера : " + System::Convert::ToString(zp_21 / chet);

			if (pr22 * 0.25 >= 1000) {

				suma_22 += pr22 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr22 * 0.25 < 1000) {
				suma_22 += 1000;
			}
			this->textBox2->Text += Environment::NewLine + "Зп 2 мастера : " + System::Convert::ToString(suma_22);

			if (chet != 6) {
				zp_22 += suma_22;
			}
			chet++;
			this->textBox2->Text += Environment::NewLine + "средняя Зп 2 мастера : " + System::Convert::ToString(zp_22 / chet);


			this->textBox3->Text += Environment::NewLine + " 1 мастер 3 цеха сумма: " + System::Convert::ToString(pr31) + " кол во автомобилей: " + System::Convert::ToString(cars31.getCount());
			this->textBox3->Text += Environment::NewLine + " 2 мастер 3 цеха сумма: " + System::Convert::ToString(pr32) + " кол во автомобилей: " + System::Convert::ToString(cars32.getCount());

			this->textBox3->Text += Environment::NewLine + "Общая выручка : " + System::Convert::ToString(pr32 + pr31) + " прибль " + System::Convert::ToString(pr31 * 0.75 + pr32 * 0.75);

			if (pr31 > pr32) {
				this->textBox3->Text += Environment::NewLine + " Первый мастер сделал выручку выше чем второй на : " + System::Convert::ToString(pr31 - pr32);
			}

			if (pr32 > pr31) {
				this->textBox3->Text += Environment::NewLine + " Второй мастер сделал выручку выше чем первый на : " + System::Convert::ToString(pr32 - pr31);
			}

			if (pr31 * 0.25 >= 1000) {

				suma_31 += pr31 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr11 * 0.25 < 1000) {
				suma_31 += 1000;
			}
			this->textBox3->Text += Environment::NewLine + "Зп 1 мастера : " + System::Convert::ToString(suma_31);

			if (chet != 6) {
				zp_31 += suma_31;
			}
			chet++;
			this->textBox3->Text += Environment::NewLine + "средняя Зп 1 мастера : " + System::Convert::ToString(zp_31 / chet);

			if (pr32 * 0.25 >= 1000) {

				suma_32 += pr32 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr32 * 0.25 < 1000) {
				suma_32 += 1000;
			}
			this->textBox3->Text += Environment::NewLine + "Зп 2 мастера : " + System::Convert::ToString(suma_32);

			if (chet != 6) {
				zp_32 += suma_32;
			}
			chet++;
			this->textBox3->Text += Environment::NewLine + "средняя Зп 2 мастера : " + System::Convert::ToString(zp_32 / chet);


			this->textBox4->Text += Environment::NewLine + " 1 мастер 4 цеха сумма: " + System::Convert::ToString(pr41) + " кол во автомобилей: " + System::Convert::ToString(cars41.getCount());
			this->textBox4->Text += Environment::NewLine + " 2 мастер 4 цеха сумма: " + System::Convert::ToString(pr42) + " кол во автомобилей: " + System::Convert::ToString(cars42.getCount());

			this->textBox4->Text += Environment::NewLine + "Общая выручка : " + System::Convert::ToString(pr42 + pr41) + " прибль " + System::Convert::ToString(pr41 * 0.75 + pr42 * 0.75);

			if (pr41 > pr42) {
				this->textBox4->Text += Environment::NewLine + " Первый мастер сделал выручку выше чем второй на : " + System::Convert::ToString(pr41 - pr42);
			}

			if (pr42 > pr41) {
				this->textBox4->Text += Environment::NewLine + " Второй мастер сделал выручку выше чем первый на : " + System::Convert::ToString(pr42 - pr41);
			}

			if (pr41 * 0.25 >= 1000) {

				suma_41 += pr41 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr41 * 0.25 < 1000) {
				suma_41 += 1000;
			}
			this->textBox4->Text += Environment::NewLine + "Зп 1 мастера : " + System::Convert::ToString(suma_41);

			if (chet != 6) {
				zp_41 += suma_41;
			}
			chet++;
			this->textBox4->Text += Environment::NewLine + "средняя Зп 1 мастера : " + System::Convert::ToString(zp_41 / chet);


			if (pr42 * 0.25 >= 1000) {

				suma_42 += pr42 * 0.25;
				//(mas11->GetTime()
			}
			else if (pr42 * 0.25 < 1000) {
				suma_42 += 1000;
			}
			this->textBox4->Text += Environment::NewLine + "Зп 2 мастера : " + System::Convert::ToString(suma_42);


			if (chet != 6) {
				zp_42 += suma_42;
			}
			chet++;
			this->textBox4->Text += Environment::NewLine + "средняя Зп 2 мастера : " + System::Convert::ToString(zp_42 / chet);


			this->textBox6->Text += Environment::NewLine + "прибль автосервиса : " + System::Convert::ToString(pr11 * 0.75 + pr12 * 0.75 + pr21 * 0.75 + pr22 * 0.75 + pr31 * 0.75 + pr32 * 0.75 + pr41 * 0.75 + pr42 * 0.75);
		}

		

		time_t time_later{ time_now + 30 * 60 }; 
		time_t i{ time_now };

		this->textBox9->Text = gcnew String(date_to_day(time_now).c_str()); 


		srand(time(NULL));

		Car *t;
		List cList;
		List all_serv;
		for (int i = 0; i < 40; i++) // создаётся рандомано машина
		{
			int tempel = rand() % 28;
			int timer = rand() % 40 + 40;
	
			t = new Car(mas_cars_plates[rand() % 27], Ser[tempel], Ser_price[tempel], rand() % 90000000000 + 10000000000, timer, rand());


			//	Car(string licenceplate, string service, int cost, int num, int time, time_t rec)

			//t = new Car(mas_cars_plates[rand() % 27], Ser[tempel], Ser_price[rand() % 28], rand() % 90000000000 + 10000000000, rand() % 101 + 20, rand());
			cList.push(t);
			all_serv.push(t);
			counter2 += timer;
		}
		cList.del_equal();
		all_serv.del_equal();

		counter1=all_serv.getCount();

		

		while (i < time_later)
		{
			int time_day;
			tm dtmp;
			localtime_s(&dtmp, &time_now);

			if (dtmp.tm_hour * 60 + dtmp.tm_min <= 720)
			{
				time_day = 15;
			}
			else if (dtmp.tm_hour * 60 + dtmp.tm_min <= 960)
			{
				time_day = 10;
			}
			else {
				time_day = 5;
			}

			Car *x1;
			int ind = rand() % 5;
			x1 = cList.FindToNumber(ind);
			cList.del_number(ind);


			bool found1 = false, found2 = false;
			bool found3 = false, found4 = false;
			for (auto s : Chex_TO) if (s == x1->GetServise()) { found1 = true; break; }
			for (auto s : Chex_KR) if (s == x1->GetServise()) { found2 = true; break; }

			for (auto s : Chex_Rimz) if (s == x1->GetServise()) { found3 = true; break; }
			for (auto s : Chex_Engine) if (s == x1->GetServise()) { found4 = true; break; }

			if (found1 == true) // 1 цех
			{
				if ((x1->GetTime() * 60 + time_now) <= time_end)
				{
					if (mas11 == NULL && mas12 == NULL)
					{
						cars11.push(x1);
						mas11 = x1;
					}

					else if (mas11 == NULL && mas12 != NULL) //если свободен 1 и занят 2 то идем к 1 мастеру
					{
						cars11.push(x1);
						mas11 = x1;
					}

					else if (mas11 != NULL && mas12 == NULL) //если свободен 2 и занят 1 то идем ко 2 мастеру
					{
						cars12.push(x1);
						mas12 = x1;
					}
					else  //если оба заняты
					{
						// добавляем в очередь 

						if (queue1.getCount() <= 4 && x1 != mas11 && x1 != mas12
							&& ((dtmp.tm_hour * 60 + dtmp.tm_min <= 1140 && dtmp.tm_wday != 6) || (dtmp.tm_hour * 60 + dtmp.tm_min <= 900 && dtmp.tm_wday == 6))) // ???????
						{
							queue1.push(x1);
						}
					}

				}
			}
			int k = 0;
			if(found2==true) // 2 цех
			{
				if ((x1->GetTime() * 60 + time_now) <= time_end) // если время услуги клиента + наст время <= конца раб дня
				{
					if (mas21 == NULL && mas22 == NULL) //если оба свободны то идем к 1 мастеру
					{
						cars21.push(x1);
						mas21 = x1;
					}

					else if (mas21 == NULL && mas22 != NULL) //если свободен 1 и занят 2 то идем к 1 мастеру
					{
						cars21.push(x1);
						mas21 = x1;
						k = k + 1;
					}

					else if (mas21 != NULL && mas22 == NULL) //если свободен 2 и занят 1 то идем ко 2 мастеру
					{
						cars22.push(x1);
						mas22 = x1;
						
						
					}

					else  //если оба заняты
					{
						if (queue2.getCount() <= 4 && x1 != mas21 && x1 != mas22
							&& ((dtmp.tm_hour * 60 + dtmp.tm_min <= 1140 && dtmp.tm_wday != 6) || (dtmp.tm_hour * 60 + dtmp.tm_min <= 900 && dtmp.tm_wday == 6))) // ???????
						{
							queue2.push(x1);
						}

					}
				}
			}
			if (found3 == true) // 3 цех
			{
				if ((x1->GetTime() * 60 + time_now) <= time_end) // если время услуги клиента + наст время <= конца раб дня
				{
					if (mas31 == NULL && mas32 == NULL) //если оба свободны то идем к 1 мастеру
					{
						cars31.push(x1);
						mas31 = x1;
					}

					else if (mas31 == NULL && mas32 != NULL) //если свободен 1 и занят 2 то идем к 1 мастеру
					{
						cars31.push(x1);
						mas31 = x1;
					}

					else if (mas31 != NULL && mas32 == NULL) //если свободен 2 и занят 1 то идем ко 2 мастеру
					{
						cars32.push(x1);
						mas32 = x1;

					}

					else  //если оба заняты
					{
						if (queue3.getCount() <= 4 && x1 != mas31 && x1 != mas32
							&& ((dtmp.tm_hour * 60 + dtmp.tm_min <= 1140 && dtmp.tm_wday != 6) || (dtmp.tm_hour * 60 + dtmp.tm_min <= 900 && dtmp.tm_wday == 6))) // ???????
						{
							queue3.push(x1);
						}

					}
				}
			}
			if (found4 == true) // 4 цех
			{
				if ((x1->GetTime() * 60 + time_now) <= time_end) // если время услуги клиента + наст время <= конца раб дня
				{
					if (mas41 == NULL && mas42 == NULL) //если оба свободны то идем к 1 мастеру
					{
						cars41.push(x1);
						mas41 = x1;
					}

					else if (mas41 == NULL && mas42 != NULL) //если свободен 1 и занят 2 то идем к 1 мастеру
					{
						cars41.push(x1);
						mas41 = x1;
					}

					else if (mas41 != NULL && mas42 == NULL) //если свободен 2 и занят 1 то идем ко 2 мастеру
					{
						cars42.push(x1);
						mas42 = x1;

					}

					else  //если оба заняты
					{
						;
						if (queue4.getCount() <= 4 && x1 != mas41 && x1 != mas42
							&& ((dtmp.tm_hour * 60 + dtmp.tm_min <= 1140 && dtmp.tm_wday != 6) || (dtmp.tm_hour * 60 + dtmp.tm_min <= 900 && dtmp.tm_wday == 6))) // ???????
						{
							queue4.push(x1);
						}

					}
				}
			}


			rep(time_day);
			i += (time_day * 60);

		}

		time_now = time_later;

		// для TO
		if (mas11 != NULL)
		{
			this->textBox1->Text += Environment::NewLine + "    Мастер 1.";
			this->textBox1->Text += Environment::NewLine + "Номер авто: " + gcnew String(mas11->GetLicenPlate().c_str());
			this->textBox1->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas11->GetServise().c_str());
			this->textBox1->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas11->GetCost());
			this->textBox1->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas11->GetTime());
		}


		if (mas12 != NULL)
		{
			this->textBox1->Text += Environment::NewLine + "    Мастер 2.";
			this->textBox1->Text += Environment::NewLine + "Номер авто:" + gcnew String(mas12->GetLicenPlate().c_str());
			this->textBox1->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas12->GetServise().c_str());
			this->textBox1->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas12->GetCost());
			this->textBox1->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas12->GetTime());
		}

		if (queue1.getCount() != 0)
		{
			for (int i = 0; i < queue1.getCount(); i++)
			{
				this->textBox5->Text += Environment::NewLine + System::Convert::ToString(i + 1) + ". Номер авто: " + gcnew String(queue1.FindToNumber(i)->GetLicenPlate().c_str());
				this->textBox5->Text += Environment::NewLine + " Тип работ: " + gcnew String(queue1.FindToNumber(i)->GetServise().c_str())
					+ ". Время работы: " + System::Convert::ToString(queue1.FindToNumber(i)->GetTime());
			}
		}


		 //для кузова
		if (mas21 != NULL)
		{
			this->textBox2->Text += Environment::NewLine + "    Мастер 1.";
			this->textBox2->Text += Environment::NewLine + "Номер авто: " + gcnew String(mas21->GetLicenPlate().c_str());
			this->textBox2->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas21->GetServise().c_str());
			this->textBox2->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas21->GetCost());
			this->textBox2->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas21->GetTime());
		}


		if (mas22 != NULL)
		{
			this->textBox2->Text += Environment::NewLine + "    Мастер 2.";
			this->textBox2->Text += Environment::NewLine + "Номер авто:" + gcnew String(mas22->GetLicenPlate().c_str());
			this->textBox2->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas22->GetServise().c_str());
			this->textBox2->Text += Environment::NewLine + "Цена  " + System::Convert::ToString(mas22->GetCost());
			this->textBox2->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas22->GetTime());
		}

		if (queue2.getCount() != 0)
		{
			for (int i = 0; i < queue2.getCount(); i++)
			{
				this->textBox6->Text += Environment::NewLine + System::Convert::ToString(i + 1) + ". Номер авто: " + gcnew String(queue2.FindToNumber(i)->GetLicenPlate().c_str());
				this->textBox6->Text += Environment::NewLine + " Тип работ: " + gcnew String(queue2.FindToNumber(i)->GetServise().c_str())
					+ ". Время работы: " + System::Convert::ToString(queue2.FindToNumber(i)->GetTime());
			}
		}


		// для шиномонтажа
		if (mas31 != NULL)
		{
			this->textBox3->Text += Environment::NewLine + "    Мастер 1.";
			this->textBox3->Text += Environment::NewLine + "Номер авто: " + gcnew String(mas31->GetLicenPlate().c_str());
			this->textBox3->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas31->GetServise().c_str());
			this->textBox3->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas31->GetCost());
			this->textBox3->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas31->GetTime());
		}


		if (mas32 != NULL)
		{
			this->textBox3->Text += Environment::NewLine + "    Мастер 2.";
			this->textBox3->Text += Environment::NewLine + "Номер авто: " + gcnew String(mas32->GetLicenPlate().c_str());
			this->textBox3->Text += Environment::NewLine + "Тип работ:: " + gcnew String(mas32->GetServise().c_str());
			this->textBox3->Text += Environment::NewLine + "Цена " + System::Convert::ToString(mas32->GetCost());
			this->textBox3->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas32->GetTime());
		}


		if (queue3.getCount() != 0)
		{
			for (int i = 0; i < queue3.getCount(); i++)
			{
				this->textBox7->Text += Environment::NewLine + System::Convert::ToString(i + 1) + ". Номер авто: " + gcnew String(queue3.FindToNumber(i)->GetLicenPlate().c_str());
				this->textBox7->Text += Environment::NewLine + " Тип работ: " + gcnew String(queue3.FindToNumber(i)->GetServise().c_str())
					+ ". Время работы: " + System::Convert::ToString(queue3.FindToNumber(i)->GetTime());
			}
		}

		// для ремонта двигателя
		if (mas41 != NULL)
		{
			this->textBox4->Text += Environment::NewLine + "    Мастер 1.";
			this->textBox4->Text += Environment::NewLine + "Номер авто: " + gcnew String(mas41->GetLicenPlate().c_str());
			this->textBox4->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas41->GetServise().c_str());
			this->textBox4->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas41->GetCost());
			this->textBox4->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas41->GetTime());
		}


		if (mas42 != NULL)
		{
			this->textBox4->Text += Environment::NewLine + "    Мастер 2.";
			this->textBox4->Text += Environment::NewLine + "Номер авто:" + gcnew String(mas42->GetLicenPlate().c_str());
			this->textBox4->Text += Environment::NewLine + "Тип работ: " + gcnew String(mas42->GetServise().c_str());
			this->textBox4->Text += Environment::NewLine + "Цена: " + System::Convert::ToString(mas42->GetCost());
			this->textBox4->Text += Environment::NewLine + "Время работы: " + System::Convert::ToString(mas42->GetTime());
		}

		if (queue4.getCount() != 0)
		{
			for (int i = 0; i < queue4.getCount(); i++)
			{
				this->textBox8->Text += Environment::NewLine + System::Convert::ToString(i + 1) + ". Номер авто: " + gcnew String(queue4.FindToNumber(i)->GetLicenPlate().c_str());
				this->textBox8->Text += Environment::NewLine + " Тип работ: " + gcnew String(queue4.FindToNumber(i)->GetServise().c_str())
					+ ". Время работы: " + System::Convert::ToString(queue4.FindToNumber(i)->GetTime());
			}
		}

	}



private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
