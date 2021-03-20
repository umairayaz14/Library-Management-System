#include<iostream>

#include<string>

#include<fstream>

#include<windows.h>

#include<iomanip>

#include<ctime>

#include<stdlib.h>

using namespace::std;

int randomize() {
  srand(time(NULL));
  int x[995];
  static int counter = 0;
  x[counter] = rand() % 1000 + 1;
  for (int y = 0; y < 995; y++) {
    if (counter != y) {

      if (x[counter] != x[y]) //to randomly generate book ID
        return x[counter];
      else {
        x[counter] = rand() % 1000 + 1;
      }

    }
  }

}

class book {
  struct node {
    int Book_ID;
    string Book_Title;
    bool Status;
    string Date;
    node * next;

  };
  int count;
  node * headptr;

  public:
    book() {

      headptr = NULL;

    }

  void addnode(int ID, string TITLE, bool ST, string DA) {
    node * newptr = new node, * temp = headptr;
    newptr -> Book_ID = ID;
    newptr -> Book_Title = TITLE;
    newptr -> Status = ST;
    newptr -> Date = DA;
    newptr -> next = NULL;

    if (headptr == NULL) {
      headptr = newptr;
      return;
    }

    while (temp -> next != NULL) {
      temp = temp -> next;
    }

    temp -> next = newptr;
  }

  void countfunc() {
    node * temp1 = headptr;
    count = 0;
    while (temp1 != NULL) {
      count++;
      temp1 = temp1 -> next;
    }
    cout << endl << "Number of nodes are: " << count << endl;
  }

  void deletenode(int ID) {
    node * ptrcurrent = headptr, * ptrprevious;
    while (ptrcurrent != NULL && ptrcurrent -> Book_ID != ID) {
      ptrprevious = ptrcurrent;
      ptrcurrent = ptrcurrent -> next;
    }
    if (ptrcurrent == NULL) {
      cout << "Record not found in the list!";
      return;
    }
    if (ptrcurrent == headptr) {
      headptr = headptr -> next;
    } else {
      ptrprevious -> next = ptrcurrent -> next;
    }
    delete ptrcurrent;
  }

  int maxID() {
    int max = 0;
    node * currentptr = headptr;
    while (currentptr != NULL) {
      if (currentptr -> Book_ID > max) {
        max = currentptr -> Book_ID;
      }
      currentptr = currentptr -> next;

    }
    return max;
  }

  void searchnode(int ID) {
    node * currentptr = headptr;
    while (currentptr != NULL && currentptr -> Book_ID != ID) {
      currentptr = currentptr -> next;

    }
    if (currentptr == NULL) {
      cout << "Record not found in the list!";

    } else {
      cout << "Data for Book is: " << endl;
      cout << "Book ID: " << currentptr -> Book_ID << endl;
      cout << "Title: " << currentptr -> Book_Title << endl;
      cout << "Status: " << currentptr -> Status << endl;
      cout << "Date of issue: " << currentptr -> Date << endl;
    }
  }

  void sort() {
    node * temphead = headptr;
    int tempid;
    string temptitle;
    bool tempstatus;
    string tempdate;
    int counter = 0;

    while (temphead) {
      temphead = temphead -> next;
      counter++;
    }
    temphead = headptr;

    for (int j = 0; j < counter; j++) {
      while (temphead ) //iterate through list until next is null
      {
        if (temphead -> Book_ID > temphead -> next -> Book_ID) {
          tempid = temphead -> Book_ID;
          temphead -> Book_ID = temphead -> next -> Book_ID;
          temphead -> next -> Book_ID = tempid;

          temptitle = temphead -> Book_Title;
          temphead -> Book_Title = temphead -> next -> Book_Title;
          temphead -> next -> Book_Title = temptitle;

          tempstatus = temphead -> Status;
          temphead -> Status = temphead -> next -> Status;
          temphead -> next -> Status = tempstatus;

          tempdate = temphead -> Date;
          temphead -> Date = temphead -> next -> Date;
          temphead -> next -> Date = tempdate;

        } else
          temphead = temphead -> next; //increment node
      }
      temphead = headptr; //reset temphead
    }
  }

  void display() {
    node * ptrtemp = headptr;
    cout << endl;
    cout << setw(25) << "Book_ID" << setw(25) << "Book_Title" << setw(25) << "Status" << setw(25) << "Date" << endl;
    while (ptrtemp->next != NULL) {
      cout << setw(22) << ptrtemp -> Book_ID << setw(30) << ptrtemp -> Book_Title << setw(20) << ptrtemp -> Status << setw(30) << ptrtemp -> Date << endl;
      ptrtemp = ptrtemp -> next;
    }
  }

};

int main() {
  int count = 5;
  int choice;
  int temp;
  int ID[1000];
  string TITLE[1000];
  bool ST[1000];
  string DA[1000];

  int ID1;
  string TITLE1;
  bool ST1;
  string DA1;

  ID[0] = 3;
  TITLE[0] = "BasicStatistics";
  ST[0] = 0;
  DA[0] = "11012019";

  ID[1] = 1;
  TITLE[1] = "ArtificialIntelligence";
  ST[1] = 1;
  DA[1] = "05102019";

  ID[2] = 4;
  TITLE[2] = "DataStructures";
  ST[2] = 1;
  DA[2] = "06112019";

  ID[3] = 5;
  TITLE[3] = "Electronics";
  ST[3] = 0;
  DA[3] = "20032019";

  ID[4] = 2;
  TITLE[4] = "AutomataTheory";
  ST[4] = 1;
  DA[4] = "01052019";

  ofstream o1;
  o1.open("book.txt");
  for (int i = 0; i < 5; i++) {

    o1 << ID[i] << " " << TITLE[i] << " " << ST[i] << " " << DA[i] << endl;

  }
  class book b1;
  ifstream i1;
  i1.open("book.txt");

  for (int i = 0; i < 5; i++) {

    i1 >> ID1;
    i1 >> TITLE1;
    i1 >> ST1;
    i1 >> DA1;

    b1.addnode(ID1, TITLE1, ST1, DA1);
  }
  system("color 80"); //it is used to add color to cosole screen
  cout << "                                           WELCOME TO LIBRARY MANAGEMENT SYSTEM";
  Sleep(1500); //it is used to add delay to console

  u:
  cout << "\n\n\n\n\n\n";
  cout << setw(80) << "|-------------------------------------|" << endl;
  cout << setw(80) << "|     LIBRARY MANAGEMENT SYSTEM       |" << endl;
  cout << setw(80) << "|   Developed by: Umair Ayaz Aslam    |" << endl;
  cout << setw(80) << "|             MAIN MENU               |" << endl;
  cout << setw(80) << "|       1) FOR DISPLAYING RECORDS     |" << endl;
  cout << setw(80) << "|       2) TO ENTER BOOK              |" << endl;
  cout << setw(80) << "|       3) TO Delete BOOK             |" << endl;
  cout << setw(80) << "|       4) TO SEARCH BOOK             |" << endl;
  cout << setw(80) << "|       5) RECORD WITH MAX BOOK ID    |" << endl;
  cout << setw(80) << "|                                     |" << endl;
  cout << setw(80) << "|        NOW ENTER YOUR CHOICE:       |" << endl;
  cout << setw(80) << "|-------------------------------------|" << endl;

  cin >> choice;
  system("CLS");
  char goback;
  switch (choice)

  {

  case 1:
    b1.sort();
    b1.display();
    b1.countfunc();
    cout << endl << "To Go To Main Menu Press u or press any other key to exit" << endl;

    cin >> goback;

    system("CLS");

    if (goback == 'u')

    {

      goto u;

    } else

    {

      cout << "\n\n\n";

      cout << setw(40) << "EXIT FROM LIBRARY MANAGEMENT SYSTEM";

    }

    break;
  case 2:

    ID[count] = randomize();
    cout << "Enter Book Title: ";
    cin >> TITLE[count];
    if (TITLE[count].length() > 30) {
      cout << "Enter Book Title: ";
      cin >> TITLE[count];
    }
    cout << "Enter Book Status: ";
    cin >> ST[count];
    cout << "Enter Book Issue Date: ";
    cin >> DA[count];
    o1 << ID[count] << " " << TITLE[count] << " " << ST[count] << " " << DA[count] << endl;

    i1 >> ID1;
    i1 >> TITLE1;
    i1 >> ST1;
    i1 >> DA1;
    b1.addnode(ID1, TITLE1, ST1, DA1);
    cout << endl << "Successful! Node has been added" << endl;
    count++;

    cout << endl << "To Go To Main Menu Press u or press any other key to exit" << endl;

    cin >> goback;

    system("CLS");

    if (goback == 'u')

    {

      goto u;

    } else

    {

      cout << "\n\n\n";

      cout << setw(40) << "EXIT FROM LIBRARY MANAGEMENT SYSTEM";

    }

    break;
  case 3:
    cout << "Enter the Book ID of the record you want to delete: ";
    cin >> temp;

    for (int i = 0; i < count; i++) {
      if (temp == ID[i]) {
        b1.deletenode(ID[i]);
        cout << endl << "Successful! Node has been deleted" << endl;
      }

    }
    cout << endl << "To Go To Main Menu Press u or press any other key to exit" << endl;

    cin >> goback;

    system("CLS");

    if (goback == 'u')

    {

      goto u;

    } else

    {

      cout << "\n\n\n";

      cout << setw(40) << "EXIT FROM LIBRARY MANAGEMENT SYSTEM";

    }

    break;

  case 4:
    cout << "Enter the Book ID of the record you want to search: ";
    cin >> temp;

    for (int i = 0; i < count; i++) {
      if (temp == ID[i]) {
        b1.searchnode(ID[i]);
      }

    }
    cout << endl << "To Go To Main Menu Press u or press any other key to exit" << endl;

    cin >> goback;

    system("CLS");

    if (goback == 'u')

    {

      goto u;

    } else

    {

      cout << "\n\n\n";

      cout << setw(40) << "EXIT FROM LIBRARY MANAGEMENT SYSTEM";

    }

    break;
  case 5:
    cout << "The book with max ID is: "<<endl;
    int maximum;
    maximum = b1.maxID();
    for (int z = 0; z < count; z++) {
      if (maximum == ID[z]) {
        cout << "Book ID: " << ID[z] << endl;
        cout << "Book Title: " << TITLE[z] << endl;
        cout << "Status: " << ST[z] << endl;
        cout << "Date: " << DA[z] << endl;
      }
    }

    for (int i = 0; i < count; i++) {
      if (temp == ID[i]) {
        b1.searchnode(ID[i]);
      }

    }
    cout << endl << "To Go To Main Menu Press u or press any other key to exit" << endl;

    cin >> goback;

    system("CLS");

    if (goback == 'u')

    {

      goto u;

    } else

    {

      cout << "\n\n\n";

      cout << setw(40) << "EXIT FROM LIBRARY MANAGEMENT SYSTEM";

    }

    break;
  }
  o1.close();
  i1.close();

  return 0;

}
