#include <iostream>
#include <string>
#include <ctime>
#include <list>

class TodoItem{
private:
int id;
std::string description;
bool completed;

public:
TodoItem(): id(0), description(""), completed(false) {}
~TodoItem()=default;

bool create(std::string new_desc) {
id=rand()%100+1;
description=new_desc;
return true;
}
int getID(){return id;}

std::string getdescription(){return description;}
bool iscompleted(){return completed;}

void setCompleted(bool val){completed=val;}


};

int main(){
char input_option;
int input_id;
std::string version="2.4.0.1";
std::string input_description;
std::list<TodoItem> todoitems;
std::list<TodoItem>::iterator it;

srand(time(NULL));


todoitems.clear();
while(1){
    system("cls");
std::cout<<"Todo exe - "<<version<<std::endl;
std::cout<<std::endl;

for(it=todoitems.begin();it!=todoitems.end();it++){
std::string completed= it->iscompleted()?"Completed":"Not Completed";
std::cout<<it->getID()<<"|"<<it->getdescription()<<":"<<it->iscompleted()<<std::endl;


}
if(todoitems.empty()){
    std::cout<<"Add Your First Task"<<std::endl;
}
std::cout<<std::endl<<std::endl;

std::cout<<"[a]dd your description"<<std::endl;
std::cout<<"[u]pdate to completed task"<<std::endl;
std::cout<<"[q]uit your todo exe"<<std::endl;
std::cout<<"Note: \n 0 means task not completed \n 1 means completed"<<std::endl<<std::endl;

std::cout<<"Enter your choice"<<std::endl;
std::cin>>input_option;

if(input_option=='q' || input_option=='Q'){
std::cout<<"Have a great day"<<std::endl;
break;
}

else if (input_option=='u' || input_option=='U'){
    std::cout<<"Enter id you want to mark as completed";
    std::cin>>input_id;

    for(it=todoitems.begin();it!=todoitems.end();it++){

 if (input_id == it->getID()) {
                    it->setCompleted(true);
                    break;
                }}
}

else if (input_option=='a'|| input_option=='A'){
std::cout<<"Enter your task detail: ";
std::cin.clear();
std::cin.ignore();
getline(std::cin, input_description);

TodoItem newItem;
newItem.create(input_description);
todoitems.push_back(newItem);
}
}
  return 0;
}
