#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix();
    Matrix(double** pvalues,int pa,int pb);
    void initialize(double** pvalues,int pa,int pb);
    void initialize(int pa,int pb);
    int getrows();
    int getcolumns();
    double getvalue(int pa,int pb);
    void setvalue(int pa, int pb,double value);
    Matrix Transpose();
    Matrix multiply(Matrix other);
    Matrix dotmultiply(Matrix other);
    Matrix sumrow();
    void addColumn(Matrix other);

private:
    double **values;
    int rows;
    int columns;

};


#endif //MATRIX_H