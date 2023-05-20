#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string, std::vector, std::ifstream, std::ofstream;

class ObjectWithId {
protected:
    string id;

public:
    void setID(const string &newID) {
        id = newID;
    }

    [[nodiscard]] string getID() const {
        return id;
    }
};

template<typename T> concept IsSubclassOfObjectWithID = std::is_base_of<ObjectWithId, T>::value;

class Customer : public ObjectWithId {
private:
    string name;
    string password;

public:
    [[nodiscard]] string getName() const {
        return name;
    }

    [[nodiscard]] string getPassword() const {
        return password;
    }

    void setName(const string &newName) {
        name = newName;
    }

    void setPassword(const string &newPassword) {
        password = newPassword;
    }

    bool operator==(const Customer &other) const {
        return other.name == this->name && other.password == this->password;
    }
};

template<typename Type> requires IsSubclassOfObjectWithID<Type>
class CrudRepository {
protected:
    string fileName;
    vector<Type> data;

    explicit CrudRepository(string _fileName) : fileName(std::move(_fileName)) {}

public:
    virtual ~CrudRepository() = default;

    CrudRepository(const CrudRepository &abstractRepository) = default;

    virtual void create(const Type &object) = 0;

    virtual vector<Type> findAll() const = 0;

    virtual bool update(const Type &oldObject, const Type &newObject) = 0;

    virtual bool remove(const Type &object) = 0;
};

template<typename Type> requires IsSubclassOfObjectWithID<Type>
class InMemoryRepository : public CrudRepository<Type> {
    explicit InMemoryRepository(string _fileName) : CrudRepository<Type>(std::move(_fileName)) {}

    void create(const Type &object) override {
        this->data.push_back(object);
    }

    [[nodiscard]] vector<Customer> findAll() const override {
        return this->data;
    }

    [[nodiscard]] bool update(const Type &oldObject, const Type &newObject) override {
        for (auto &it: this->data) {
            if (it.getID() == oldObject.getID()) {
                it = newObject;
                return true;
            }
        }
        return false;
    }

    [[nodiscard]] bool remove(const Type &object) override {
        for (int i = 0; i < this->data.size(); i++) {
            if (this->data[i].getID() == object.getID()) {
                this->data.erase(this->data.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}