#include <iostream>
#include <string>
#include <sstream>

main ()
{
  std::string para;
  std::string num;
  std::string word;  
  std::string p;
  std::getline (std::cin,para);
  int n;
  int place=0;
  int person=0;
  std::getline (std::cin,num);
  n=atoi(num.c_str());
    for(int i=0;i<n;i++){
        std::getline (std::cin,word);
    	int pos=para.find(word);
   		int length=word.length();
x:		if(para[pos+length]==',')
		   		place++;
		if(para[pos+length]=='\'')
		   		person++;
		if(para[pos+length]=='.'){
		   		person++;
				place++;
		}
		p=para.substr(pos-10,pos+length+10);
		if((p.find("he")>0)||((p.find("she")>0)||((p.find("him")>0)||((p.find("her")>0))
		   		person++;
		if((p.find("via")>0)||((p.find("in")>0)||((p.find("there")>0)||((p.find("from")>0))
		   		place++;
		
		if(person>place)
		   		cout<<"person"<<endl;
		else if(person<place)
			   cout<<"place"<<endl;
		else
		   {
		   		std:string new=para.substr(pos+length);
		   		p=new.substr(pos-10,pos+length+10);
				pos=new.find(word);
				goto x;
		   }		

	}  
    
  return 0;
}
