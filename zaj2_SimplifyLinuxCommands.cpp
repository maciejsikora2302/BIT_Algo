//używanie stacku do zmiany linuxowych komend (np. /a/ /b/ ../../c na wynik /c)


string* split(string a, string sep)// prototyp funkcji zwracającej tablicę stringów która została rozdzielona względem danego separatora

string simplify(string in){
    string tmp=split(in."/");
    int i=0;
    stack s;
    while(i<tmp.size()){
        if(tmp[i]==".") i++;
        else if (tmp[i]=="..") {
            pop(s); //zakładamy, że jak jest puste to zwraca null, whatever
            i++;
        }else{
            push(s,tmp[i]);
            i++;
        }
    }
    string result;
    while(!is_empty(s)){
        result=pop(s)+result;
        result="/"+result;
    }
    return (is_empty(result)) ? "/" : result;
}
