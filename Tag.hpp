#ifndef TAG_HPP
#define TAG_HPP

#include<string>

class Tag
{
 private:
   int id;
   std::string name;  

 public:
   Tag(int id,std::string name){
       this->id=id;
       this->name=name;
   }

    std::string getTag(){
        return name;
    } 

    int getId(){
        return id;
    }
};

#endif