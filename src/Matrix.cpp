#include "Matrix.h"

Matrix::Matrix()
{
    values=nullptr;
    rows=0;
    columns=0;
}

Matrix::Matrix(double** pvalues,int pa,int pb)
{
    rows=pa;
    columns=pb;
    values=new double*[rows];
    for(int i=0;i<rows;i++)
    {
        values[i]=new double[columns];
        for(int j=0;j<columns;j++)
        values[i][j]=pvalues[i][j];
    }
}

void Matrix::initialize(double** pvalues,int pa,int pb)
{
    rows=pa;
    columns=pb;
    values=new double*[rows];
    for(int i=0;i<rows;i++)
    {
        values[i]=new double[columns];
        for(int j=0;j<columns;j++)
        values[i][j]=pvalues[i][j];
    }
}

void Matrix::initialize(int pa,int pb)
{
    rows=pa;
    columns=pb;
    values=new double*[rows];
    for(int i=0;i<rows;i++)
    {
        values[i]=new double[columns];
    }
}



int Matrix::getrows()
{
    return rows;
}


int Matrix::getcolumns()
{
    return columns;
}

double Matrix::getvalue(int pa, int pb)
{
    return values[rows][columns];
}

void Matrix::setvalue(int pa, int pb,double value)
{
    values[rows][columns]=value;
}

Matrix Matrix::Transpose()
{
    double** pvalues=new double*[columns];
    for(int i=0;i<columns;i++)
    {
        pvalues[i]=new double[rows];
        {
            for(int j=0;j<rows;j++)
            pvalues[i][j]=values[j][i];
        }
    }
    Matrix res(pvalues,columns, rows);
    return res;
}

Matrix Matrix::multiply(Matrix other)
{
    double **pvalues=new double*[rows];
    for(int i=0;i<rows;i++)
    {
        pvalues[i]=new double[other.getcolumns()];
        for(int j=0;j<other.getcolumns();j++)
        {
            pvalues[i][j]=0;
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            for(int k=0;k<other.getrows();k++)
            {
                for(int l=0;l<other.getcolumns();l++)
                {
                    pvalues[i][l]+=values[i][j]*other.getvalue(k,l);
                }
            }
        }
    }
    Matrix res(pvalues,rows,other.getcolumns());
    return res;
}

Matrix Matrix::dotmultiply(Matrix other)
{
    double **pvalues=new double*[rows];
    for(int i=0;i<rows;i++)
    {
        pvalues[i]=new double[columns];
        for(int j=0;j<columns;j++)
        {
            pvalues[i][j]=values[rows][columns]*other.getvalue(rows,columns);
        }
    }
    Matrix res(pvalues,rows,columns);
    return res;
}

Matrix Matrix::sumrow()
{
    double **pvalues=new double*[1];
    pvalues[0]=new double[columns];
    for(int i=0;i<columns;i++)
    {
        pvalues[i]=0;
        for(int j=0;j<rows;j++)
            pvalues[0][i]+=values[j][i];
    }
    Matrix res(pvalues,1,rows);
    return res;

}

void Matrix::addColumn(Matrix other)
{
    double **pvalues=new double*[rows+1];
    for(int i=0;i<rows;i++)
    {
        pvalues[i]=values[i];
    }
    pvalues[rows]=new double[columns];
    for(int i=0;i<columns;i++)
    {
        pvalues[rows][i]=other.getvalue(0,i);
    }
}