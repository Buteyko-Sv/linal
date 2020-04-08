#include "matrix.h"

    Matrix :: Matrix(unsigned int m, unsigned int n)
    {
        this->m=m;
        this->n=n;
        value=new double *[m];
        for(unsigned int i=0; i<m; i++)
        {
            value[i]=new double[m];
        }
    };
    Matrix :: Matrix(unsigned int m, unsigned int n, double **value)
    {
        this->m=m;
        this->n=n;
        value=new double *[m];
        for(unsigned int i=0; i<this->m; i++)
        {
            value[i]=new double[this->m];
        }
        for(unsigned int i=0; i<this->m; i++)
            for(unsigned int j=0; j<this->n; j++)
            this->value[i][j]=value[i][j];
    };
    Matrix :: ~Matrix()
    {
        delete [] value;
    };//destructor

    double Matrix :: getValue(unsigned int i, unsigned int j) const
    {
        return this->value[i][j];
    };
    unsigned int Matrix :: getM() const
    {
        return this->m;
    };
    unsigned int Matrix :: getN() const
    {
        return this->n;
    };

    void Matrix :: setValue(unsigned int i, unsigned int j, double value)
    {
        this->value[i][j]=value;
    };

    bool Matrix :: operator== (const Matrix& M) const
    {
        bool c=true;
        if(this->getM()==M.getM() && this->getN()==M.getN())
        {
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        c*=(this->getValue(i, j)==M.getValue(i, j));

                    }
            }
        }
        return c;
    };
    bool Matrix :: operator!= (const Matrix& M) const
    {
        return !(*(this)==M);
    };

    Matrix Matrix :: operator+ (const Matrix& M) const
    {

        if(this->getM()==M.getM() && this->getN()==M.getN())
        {
            Matrix Mtemp(M.getM(), M.getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)+M.getValue(i, j));
                    }
            }
            return Mtemp;
        }
    };
    Matrix Matrix :: operator+= (const Matrix& M) const
    {
        if(this->getM()==M.getM() && this->getN()==M.getN())
        {
            Matrix Mtemp(M.getM(), M.getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)+M.getValue(i, j));
                    }
            }
            return Mtemp;
        }
    };
    Matrix Matrix :: operator- (const Matrix& M) const
    {
        if(this->getM()==M.getM() && this->getN()==M.getN())
        {
            Matrix Mtemp(M.getM(), M.getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)-M.getValue(i, j));
                    }
            }
            return Mtemp;
        }
    };
    Matrix Matrix :: operator-= (const Matrix& M) const
    {
        if(this->getM()==M.getM() && this->getN()==M.getN())
        {
            Matrix Mtemp(M.getM(), M.getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)-M.getValue(i, j));
                    }
            }
            return Mtemp;
        }
    };
    Matrix Matrix :: operator* (const double a) const
    {
            Matrix Mtemp(this->getM(), this->getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)*a);
                    }
            }
            return Mtemp;
    };
    Matrix Matrix :: operator*= (const double a) const
    {
            Matrix Mtemp(this->getM(), this->getN());
            for(unsigned int i=0; i<this->getM(); i++)
            {
                for(unsigned int j=0; j<this->getN(); j++)
                    {
                        Mtemp.setValue(i, j, this->getValue(i, j)*a);
                    }
            }
            return Mtemp;
    };

    Matrix Matrix :: operator* (const Matrix& M) const
    {
        unsigned int m1=this->getM(), n1=M.getN();
        if(this->getN()==M.getM())
        {
            Matrix Mtemp(m1, n1);
            unsigned int n0=M.getM();
            for(unsigned int i=0; i<m1; i++)
            {
                for(unsigned int j=0; j<n1; j++)
                {
                    double temp=0;
                    for(unsigned int k=0; k<n0; k++)
                    {
                        temp+=this->getValue(i, k)*M.getValue(k, j);
                    }
                    Mtemp.setValue(i, j, temp);
                }
            }
            return Mtemp;
        }
    };

    Matrix Matrix :: transpose() const
    {
        Matrix Mtemp(this->getN(), this->getM());
        for(unsigned int i=0; i<Mtemp.getM(); i++)
        {
            for(unsigned int j=0; j<Mtemp.getN(); j++)
            {
                Mtemp.setValue(i, j, this->getValue(j, i));
            }
        }
        return Mtemp;
    };

std::ostream& operator<<(std::ostream& out, const Matrix& M)
{
    for(unsigned int i=0; i<M.getM(); i++)
    {
        for(unsigned int j=0; j<M.getN(); j++)
            out<<M.getValue(i, j);
        out<<std::endl;
    }
    return out;
}
std::istream& operator>>(std::istream &in, Matrix &M)
{
    double v=0;
    for(unsigned int i=0; i<M.getM(); i++)
    {
        for(unsigned int j=0; j<M.getN(); j++)
        {
            in>>v;
            M.setValue(i, j, v);
        }
    }
    return in;
}
