#include<MODEL/residenza.h>

Residenza::Residenza(const QString& c, const QString& v, const QString& n) : comune(c), via(v), num_Civico(n) {}

void Residenza::setResidenza(const QString& c, const QString& v, const QString& n) {
        comune = c;
        via = v;
        num_Civico = n;
}

Residenza* Residenza::readResidenza(QXmlStreamReader& xmlReader) {
    Residenza* res = new Residenza();
    xmlReader.readNext();
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "residenza")){
        if(xmlReader.isStartElement() && xmlReader.name() == "comune"){
            res->comune = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "via"){
            res->via = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "numerocivico"){
            res->num_Civico = xmlReader.readElementText();
        }
        else xmlReader.readNext();
    }
    return res;
}

const QString& Residenza::getComune() const {
    return comune;
}
const QString& Residenza::getVia() const {
    return via;
}
const QString& Residenza::getNumCivico() const {
    return num_Civico;
}

void Residenza::setComune(const QString& c){
    comune = c;
}
void Residenza::setVia(const QString& v){
    via = v;
}
void Residenza::setNumCivico(const QString& n){
    num_Civico = n;
}
