#include <iostream>
using namespace std;

class Link{
public:
    int data;
    Link *next;
    Link (int newData) {
        data = newData;
        next = NULL;
        }
    void show() {
        cout << "{" << data << "}";
    }
};

class CircList{
    private:
        Link *current;
        int numLinks;
    public:
        CircList() {
            current = NULL;
            numLinks = 0;
        }

        bool empty() {
            return (numLinks == 0);
        }

        bool search(int valueToFind){
            if (!empty()) {
                for (int i = 0; i < numLinks; i++) {
                    if (current->data == valueToFind) {
                        return true;
                    }
                    current = current->next;
                }
            }
            return false;
        }

        void displayList() {
            cout << "The list: ";
            if( !empty() ){
                for (int i = 0; i < numLinks; i++){
                    current->show();
                    current = current->next;
                }
            }
            else {
                cout << "is empty\n";
            }
        }

        void insertAfterValueFound(int newValue, int valueToFind){
            Link *newLink = new Link(newValue);
            if (!empty()) {
                for (int i = 0; i < numLinks; i++) {
                    if (current->data == valueToFind){
                        newLink->next = current->next;
                        current->next = newLink;
                        numLinks++;
                    }
                }
            }
        }

        void insertInitialLink(int newValue){
            Link *newLink = new Link(newValue);
            current = newLink;
            current->next = newLink;
            numLinks++;
        }
};

int main() {
    CircList *c = new CircList();
    cout << boolalpha;
    c->displayList();
    c->insertInitialLink(2);
    c->displayList();
    c->insertAfterValueFound(5, 2);
    c->displayList();
}