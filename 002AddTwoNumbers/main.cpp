#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * head = new ListNode(0);
        ListNode * tail = head;

        int rest = 0;
        while( p1 != NULL || p2 != NULL || rest > 0){

            int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + rest;
            rest = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if( p1 != NULL ) {
                p1 = p1->next;
            }

            if( p2 != NULL ) {
                p2 = p2->next;  
            }
        }

        tail = head;
        head = head->next;
        delete tail;
        return head;
    }

    ListNode * copyList(ListNode * list) {
        ListNode * p = list;
        ListNode * newHead = NULL;
        ListNode * newP = NULL;
        while(p!= NULL) {
            ListNode * newQ = new ListNode(p->val);

            if( newP == NULL ) {
                newHead = newQ;
            } else {
                newP->next = newQ;
            }

            newP = newQ;
            p = p->next;
        }

        return newHead;
    }

    void deleteList(ListNode* head) {
        if( head == NULL ) {
            return;
        }

        do {
            ListNode *p = head->next;
            delete head;
            head = p;
        } while(head != NULL);
    }

    ListNode * createList(int number) {
        ListNode * p = NULL;
        ListNode * head = NULL;
        int n = number;

        if( number == 0 ) {
            p = new ListNode(0);
            return p;
        }

        while( n != 0 ) {
            ListNode * q = new ListNode(n%10);
            if( p != NULL ) {
                p->next = q;
            } 
            p = q;
            n = n / 10;
            if( head == NULL ) {
                head = p;
            }
        }

        return head;
    }

    bool checkAnswer(ListNode * answer, int number) {
        ListNode * p = answer;
        int n = number ;

        if( n == 0 ) {
            if( p != NULL && p->next == NULL && p->val == 0 ) {
                return true;
            }

            return false;
        }

        while(p != NULL) {
           std::cout << p->val << " ";
           if( p->val != n % 10 ) {
               return false;
           }

           p = p->next;
           n = n / 10;
        }

        return ( n == 0 );
    }
};



int main(){
    Solution s;
    
    //case 1: both are empty
    std::cout << "case 1: both are empty. ";
    ListNode * answer = s.addTwoNumbers(NULL,NULL);
    if(answer == NULL) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 2: create list
    std::cout << "case 2: create list for 0. ";
    ListNode * number1 = s.createList(0);
    if(s.checkAnswer(number1,0) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 3: create list
    std::cout << "case 3: create list for 1. ";
    number1 = s.createList(1);
    if(s.checkAnswer(number1,1) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 4: create list
    std::cout << "case 4: create list for 12. ";
    number1 = s.createList(12);
    if(s.checkAnswer(number1,12) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;

    //case 5: one list has number
    std::cout << "case 5: one list has number. ";
    number1 = s.createList(12);
    answer = s.addTwoNumbers(number1,NULL);
    if(s.checkAnswer(answer,12) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 6: one list has number
    std::cout << "case 6: one list has number. ";
    number1 = s.createList(12);
    answer = s.addTwoNumbers(NULL,number1);
    if(s.checkAnswer(answer,12) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 7: both list have number.
    std::cout << "case 7: 1+2=3 ";
    number1 = s.createList(1);
    ListNode *number2 = s.createList(2);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,3) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 8: both list have number.
    std::cout << "case 8: 4 + 7 = 11 ";
    number1 = s.createList(4);
    number2 = s.createList(7);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,11) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 9: both list have number.
    std::cout << "case 9: 11 + 2 = 13 ";
    number1 = s.createList(11);
    number2 = s.createList(2);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,13) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 10: both list have number.
    std::cout << "case 10: 1 + 12 = 13 ";
    number1 = s.createList(1);
    number2 = s.createList(12);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,13) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 11: both list have number.
    std::cout << "case 11: 12 + 9 = 21 ";
    number1 = s.createList(12);
    number2 = s.createList(9);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,21) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 12: both list have number.
    std::cout << "case 12: 99 + 1 = 100 ";
    number1 = s.createList(99);
    number2 = s.createList(1);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,100) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);

    //case 12: both list have number.
    std::cout << "case 13: 990 + 10 = 1000 ";
    number1 = s.createList(990);
    number2 = s.createList(10);
    answer = s.addTwoNumbers(number1,number2);
    if(s.checkAnswer(answer,1000) == true) {
        std::cout << "ok";
    } else {
        std::cout << "error";
    }
    std::cout << endl;
    s.deleteList(answer);
}
