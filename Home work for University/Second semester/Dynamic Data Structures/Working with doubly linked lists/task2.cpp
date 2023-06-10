#include <iostream>
#include <unordered_set>

using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

//вставка элемента в конец списка
void push(list *&h, list *&t, int x) {
    list *r = new list; //создаём новый элемент
    r->inf = x;//заполняем информационное поле нового элемента
    r->next = NULL; //заполняем ссылочное поле нового элемента
    if (!h && !t) { //если список пуст
        r->prev = NULL; //r будет первым элементом
        h = r;//голова р будет ссылаться на r
    }
    else {
        t->next = r; //следующий для хвоста для хвоста - это r
        r->prev = t;//предыдущим элементом для r будет t
    }
    t = r; //хвост t будет указывать на r
}

//вывод элементов списка
void print(list *&h, list *&t) {
    list *p = h;//указатель на голову
    while (p) { //пока не дошли до конца
        cout << p->inf << " ";//выводим
        p = p->next;//переход к следующему
    }
}

//удаление всех повторяющихся элементов
void deletePovtor(list *&h, list *&t) {
    unordered_set <int> unique_values;
    list* currNode = *&h;
    while (currNode != nullptr) {
        if (unique_values.find(currNode->inf) != unique_values.end()) {
            if (currNode->next != nullptr) {
                currNode->next->prev = currNode->prev;
            } else {
                t = currNode->prev;
            }
            currNode->prev->next = currNode->next;
            list *temp = currNode;
            currNode = currNode->next;
            delete temp;
        }
        else {
            unique_values.insert(currNode->inf);
            currNode = currNode->next;
        }
    }
}

int main() {
    int n, y;
//инициализируем список
    list *h = NULL;
    list *t = NULL;
    cout << "n= ";
    cin >> n;//вод количества элементов
    for (int i = 0; i < n; i++) { //ввод самих элементов
        cin >> y;
        push(h, t, y); //добавление элемента в стек
    }
    deletePovtor(h, t);
    print(h, t);//выводим полученный список
    return 0;
}