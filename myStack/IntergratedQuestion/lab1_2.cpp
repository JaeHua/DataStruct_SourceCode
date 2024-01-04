
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string transs(string exp) {
    stack<char> sym;
    string postexp = "";

    for(int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if(c == ' ') continue; // 忽略空格
        else if(c == '(') sym.push(c);
        else if(c == ')') {
            while(sym.top() != '(') {
                postexp += sym.top();
                sym.pop();
            }
            sym.pop(); //弹出'('
        }
        else if(c == '+' || c == '-') {
            while(!sym.empty() && sym.top() != '(') {
                postexp += sym.top();
                sym.pop();
            }
            sym.push(c);
        }
        else if(c == '*' || c == '/') {
            while(!sym.empty() && (sym.top() == '*' || sym.top() == '/')) {
                postexp += sym.top();
                sym.pop();
            }
            sym.push(c);
        }
        else if (c == '=')
        {
            break;
        }
        else
        {
            string d = "";
            while(c >= '0'&&c<='9')
            {
                d += c;
                i++;
                if(i < exp.length())
                    c = exp[i];
                else
                    break;

            }
            i--;
            postexp += d;
            postexp += "#";//标识
        }
    }

    while(!sym.empty()) {
        postexp += sym.top();
        sym.pop();
    }

    return postexp;
}
int cacl(string expp)
{
    stack<int>num;
    char ch;
    int i = 0;
    int a,b,c;
    while(i < expp.length())
    {
        ch = expp[i];
        if(ch == '+')
        {
             a = num.top();
            num.pop();
            b = num.top();
            num.pop();
             c = a + b;
             num.push(c);
        }
        else if(ch == '-')
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            c = b - a;
            num.push(c);
        }
        else if (ch == '*')
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            c = a * b;
            num.push(c);
        }
        else if(ch == '/')
        {
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            c = b/a;
            num.push(c);
        }
        else
        {
            int d = 0;
            while (ch >= '0' && ch <= '9')
            {
                d = 10*d + ch - '0';
                i++;
                ch = expp[i];
            }
            num.push(d);

        }
        i++;//#会被跳过
    }
    return num.top();
}
int main() {
    string ex;
    getline(cin, ex);

    string post = transs(ex);
    int ans = 0;
    ans = cacl(post);
    cout<<post<<endl;
    cout<<ans<<endl;
    return 0;
}
