#ifndef CATALOG_H
#define CATALOG_H

#include <string>
using namespace std;

class Catalog {
private:
    string catalogID;
    string itemCount;

public:
    Catalog();
    ~Catalog();
    
    string getCatalogID();
    void setCatalogID(string id);
    string getItemCount();
    void setItemCount(string count);
    void viewCatalog();
};

#endif
