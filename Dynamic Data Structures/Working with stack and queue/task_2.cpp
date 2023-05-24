#include<iostream>
using namespace std;

 struct stack {
	 int inf;
	 stack * next;
	
};

 void push(stack * &h, int x) {//�������
	 stack * r = new stack;
	 r -> inf = x;
	 r -> next = h;
	 h = r;
	
}

 int pop(stack * &h) { //��������
	 int i = h -> inf;
	 stack * r = h;
	 h = h -> next;
	 delete r;
	 return i;
	
}


 void reverse(stack * &h) { //"���������"�����
	 stack * head1 = NULL; //������������� ��������� �����
	 while (h) //���� ���� �� ����
		 push(head1, pop(h)); //������������ �� ������ ����� � ������
	 h = head1; //�������������� ���������
	
}

 bool prost(int n) {
	 for (int i = 2; i <= sqrt(n); i++) {
		 if (n % i == 0)
			 return false;
	 }
	 return true;
 }
 

 stack * result(stack * &h) {
	 stack * res = NULL; //�������������
	 stack * h1 = NULL;
	 while (h) {
		 int x = pop(h); //������� ������ �������
		 push(res, x); //���������� � ���������
		while (h) {
			 int y = pop(h); //������� ������� �� �����
			 if (!prost(y)) push(h1, y); //���������� � ����� ����
			
		}
		 reverse(h1); //�������������� ����
		 h = h1; //�������������� ���������
		 h1 = NULL;
		
	}
	 reverse(res); //�������������� �������������� ����
	 return res;
	
}

int main() {
	 int n;
	 cout << " n = 9 \n"; n = 9;
	 stack * head = NULL; //�������������
	 int x;
	 for (int i = 0; i < n; i++) { //������� ����
		 cin >> x;
		 push(head, x);
	 }
	 reverse(head); //�������������� ����
	 stack * res = result(head); //���������
	 while (res)
		 cout << pop(res) << " "; //������� �� �����
	
		 cout << endl;
	 return 0;
	
}
