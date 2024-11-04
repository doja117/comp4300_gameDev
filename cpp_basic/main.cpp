#include<iostream>
#include<vector>
#include<fstream>
class Student {
    std::string firstName;
    std::string lastName;
    int std_id=01;
    double grade_avg;
    static int totalStudentCount;
    public:
    Student()
    :firstName(""),lastName(""),std_id(0),grade_avg(0)
    {
        totalStudentCount+=1;
    }   
    Student(std::string firstName,std::string lastName,int id,float avg)
    :firstName(firstName),  lastName(lastName), std_id(id), grade_avg(avg)
    {
        totalStudentCount+=1;
    }
    double getAvg() const {return this->grade_avg;}
    int getId() const{return this->std_id;}
    int getTotalStudentCount() const {
        return this->totalStudentCount;
    }

    void print() const {
        std::cout<<firstName<<"\t"<<lastName<<"\n";
    }
    
};  int Student::totalStudentCount=0;


class Course{
    std::string m_name="Course";
    std::vector<Student>m_students;
    public:
    Course(){}
    Course(const std::string& name)
    :m_name(name)
    {
    }
    void addStudent(const Student& s){
        m_students.push_back(s);
    }

    const std::vector<Student>&getStudents() const{
        return m_students;
    }

    void print() const {
        for (auto& s:m_students){
            s.print();
        }
    }

    void loadFromFile(std::string& fileName){
       std::ifstream fin(fileName);
       std::string first,last;
       int id;  double avg;
       while (fin >> first){
            fin>>last>>id>>avg;
            addStudent(Student(first,last,id,avg));
       }
    }

};


int main(){
   Course c("Comp 43000");
   std::string fileLoc="Students.txt";
   c.loadFromFile(fileLoc);
   c.print();

}






