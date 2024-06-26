#ifndef COMMENT
#define COMMENT

#include <string>
#include "User.hpp"

class Comment{
private:
    int id;
    std::string title;   
    std::string text;
    User *author;
public:
    Comment(int id,std::string title,std::string text, User *author){
        this->id=id;
        this->title=title;
        this->text=text;
        this->author=author;
    }

    int getId() const {
        return id;
    }

    std::string getTitle()  {
        return title;
    }

    std::string getText()  {
        return text;
    }

    User* getAuthor()  {
        return author;
    }
};

#endif