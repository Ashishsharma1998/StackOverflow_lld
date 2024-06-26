#include "stackoverflow.hpp"
#include "Question.hpp"
#include<iostream>
#include "Comment.hpp"
using namespace std;

int main(){

    StackOverflow *st = StackOverflow::getInstance();
            // Register users
        User *user1 = new User(1, "john", "john@example.com","password123", 0);
        User *user2 = new User(2, "jane", "jane@example.com","password456", 0);
        st->registerUser(user1);
        st->registerUser(user2);
        
         // User login
        User *loggedInUser = st->loginUser("john", "password123");
        if (loggedInUser != nullptr) {
            cout<<"User logged in: "<<(loggedInUser->getUsername())<<endl;
        } else {
            cout<<"Invalid username or password."<<endl;
        }


        // Post a question
        vector<Tag*> tags =  {new Tag(1, "java") , new Tag(2, "programming")};
        vector<Comment*> comments;
        vector<Answer*> answers;
        Question *question1 = new Question(1,user1,0,"Please explain Java.", "What is Java?",comments,answers,tags);
        st->postQuestion(question1);


        // //post answer 
        Answer *answer1 = new Answer(1,user2,0, "Java is an object-oriented programming language.",comments,question1);
        st->postAnswer(answer1);
         
         //get answer 
         cout<<"answers on question1"<<endl;
         for(auto ans:st->getAnswer(question1)){
             cout<<ans->getBody()<<"  ans by "<<ans->getAuthor()->getUsername()<<endl;
         }
         
        // //vote question
        st->voteQuestion(question1, 1);

        cout<<question1->getVoteCount()<< "vote count"<<endl;

        st->voteQuestion(question1,5);

        cout<<question1->getVoteCount()<< "vote count"<<endl; 
        //  // Search for questions
        vector<Question*> searchResults = st->searchQuestions("Java");
        cout<<"Search Results:"<<endl;
        for(Question* question : searchResults) {
            cout<<question->getTitle()<<endl;
        }

        // // Get questions by tag
        vector<Question*> taggedQuestions = st->searchByTagName("java");
        cout<<"Questions tagged with 'java':"<<endl;
        for (Question* question : taggedQuestions) {
            cout<<question->getTitle()<<endl;
        }

        // // Get questions by user
        vector<Question*> userQuestions = st->getQuestionsByUser(user1);
        cout<<"Questions posted by user1:"<<endl;
        for (Question* question : userQuestions) {
            cout<<question->getTitle()<<endl;
        }


        //postComment on Answer
        Comment *c1 = new Comment(1,"Java","Actually it's a hybrid programming language",user1);
        st->postCommentOnAnswer(c1,answer1);

        
        // getComment on answers
        cout<<"comment on answers"<<endl;
        for(auto comment:st->getCommentOnAnswer(answer1)){
           cout<<comment->getText()<<" "<<"commented by "<<comment->getAuthor()->getUsername()<<endl;
        }

    return 0;
}