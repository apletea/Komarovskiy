#include <iostream>

using namespace std;

class Drob{
    private: int kol;int z;int m;
    public:
        Drob(int n, int d, int c){
            if (d == 0){
                cout << "divider cant be qual 0" << endl;
            }
            set(n,d,c);
        };
        Drob(){
            set(0,1,0);
        };
        Drob(int n){
        set(0,1,n);
        }
        Drob (Drob const &src){
            this->z=src.get_z();
            this->m=src.get_m();
            this->kol=src.get_kol();
        };
        Drob operator+(const Drob &other){
            return add(other);
        };
        Drob operator*(const Drob &other){
            return mult(other);
        };
        Drob operator-(const Drob &other){
            return minus(other);
        };
        Drob operator/(const Drob &other){
            return divid(other);
        };
        Drob operator=(const Drob &other){
            set(other.get_z(),other.get_m(),other.get_kol());
            return *this;
        };
        ~Drob(){

        if (this->z!=0 && this->kol!=0){}
            delete this;

        }
        bool operator==(const Drob &other){
            Drob a = *this;
            Drob b = other;
            return (!(this->kol-other.get_kol()) && !(this->m-other.get_m()) && !(this->z-other.get_z())  );
        };
        ostream &operator<<(ostream &os){
            os << this->kol << "+" << this->z << "/" << this->m;
            return os;
        };
        int get_z() const{
            return this->z;
        };
        int get_m() const{
            return this->m;
        };
        int get_kol() const{
            return this->kol;
        };
         int get_z() {
            return this->z;
        };
        int get_m() {
            return this->m;
        };
        int get_kol() {
            return this->kol;
        };
    private:
        Drob divid(Drob tmp){
            int v = this->kol*this->m+this->z;
            int l = tmp.get_kol()*tmp.get_m()+tmp.get_z();
            this->z = v*tmp.get_m();
            this->m = this->m*l;
            this->kol = 0;
            set (this->z, this->m, 0);
            return *this;
        };
        Drob minus(Drob tmp){
            set(this->z*tmp.get_m()-this->m*tmp.get_z(),this->m*tmp.get_m(),this->kol-tmp.get_kol());
            return *this;
        };
        Drob add(Drob tmp){
            set(this->z*tmp.get_m()+this->m*tmp.get_z(),this->m*tmp.get_m(),this->kol+tmp.get_kol());
            return *this;
        };
        Drob mult(Drob tmp){
            int v = this->kol*this->m+this->z;
            int l = tmp.get_kol()*tmp.get_m()+tmp.get_z();
            this->z = v*l;
            this->m = this->m*tmp.get_m();
            this->kol = 0;
            set (this->z, this->m, 0);
            return *this;
        };
        void set(int a, int b,int c){
            this->z = a/gcf(a,b);
            this->m = b/gcf(a,b);
            this->kol = c;
            if (a/b >= 1){
                int u = a/b;
                this->kol = this->kol + u;
                this->z = this->z - u*b;
            }
        };
        int gcf(int a, int b){
            if (a % b == 0)
                return b;
            else return gcf(b, a%b);
        };

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
