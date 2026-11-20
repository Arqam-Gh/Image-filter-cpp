#include "Catalog.h"
#include <iostream>
using namespace std;

Catalog::Catalog() : catalogID(""), itemCount("") {
}

Catalog::~Catalog() {
}

string Catalog::getCatalogID() {
    return catalogID;
}

void Catalog::setCatalogID(string id) {
    catalogID = id;
}

string Catalog::getItemCount() {
    return itemCount;
}

void Catalog::setItemCount(string count) {
    itemCount = count;
}

void Catalog::viewCatalog() {
}
