#include <iostream>
#include <vector>
#include <memory>
using namespace std;


class File{
protected:
    string name;
    int id;
public:
    File(const string& name, int id):name(name),id(id){}
    File(const File& other) = delete;
    virtual ~File() = default;
    File& operator=(const File& other) = delete;
    void setId(int new_id){ // setName
         id=new_id;
    }
    int getId()const{return id;}
    virtual void print(ostream& os)const=0;
};

class TextFile: public File{
    private:
        string text;
    public:
        TextFile(const string& name, int id, const string& text):File(name, id), text(text){}
        void print(ostream& os)const override{
            os<<text;
        }
        void setText(const string& new_text){
            text=new_text;
        }
        const string& getText()const{return text;}
};


class Directory: public File{
    private:
        vector<shared_ptr<File>> files;
    public:
        Directory(string name, int id):File(name, id){}
        Directory(const File& other) = delete;    
        ~Directory()=default;

        vector<shared_ptr<File>>::iterator begin(){
            return files.begin();
        }
        vector<shared_ptr<File>>::iterator end(){
            return files.end();
        }
        vector<shared_ptr<File>>::const_iterator begin() const{
            return files.begin();
        }
        vector<shared_ptr<File>>::const_iterator end()const{
            return files.end();
        }
    
};


shared_ptr<File> findFile(const Directory& dir, int id){
    
    for(shared_ptr<File> file : dir){
        if(file->getId()== id) return file ;
        Directory* temp_dir = dynamic_cast<Directory*>(file.get());
        if(temp_dir){
            shared_ptr<File> result = findFile(*(temp_dir), id);
        if(result !=NULL){return result;}
        }
    }
    return NULL;
}





int main(){

    return 0;
}