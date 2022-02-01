import java.util.Scanner;
public class matrix {
    int[][] matrix;
    int row,column;
    Scanner lmao = new Scanner(System.in);

    public matrix(){
        System.out.println("Initializing Matrix");
        System.out.println("Enter the number of rows and columns of the matrix");
        row = lmao.nextInt();
        column = lmao.nextInt();
        matrix = new int[row][column]; 
    }

    public matrix(int rows,int columns){
        row = rows;
        column = columns;
        matrix = new int[row][column];
    }

    public void setMatrix(){
        System.out.println("Enter values to fill into matrix");
        for(int i =0;i<row;i++){
            for(int j=0;j<column;j++){
                System.out.println("Enter element in row " + i + " and column " + j );
                matrix[i][j] = lmao.nextInt();
            }
        }
    }

    public void displayMatrix(){
        for(int i = 0;i<row;i++){
            for(int j = 0;j<column;j++){
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.print("\n");
        }
    }

    public static matrix product(matrix m1,matrix m2){
        matrix m3;
        if (m1.column != m2.row) {
            System.out.println("Cannot perform matrix multiplication on this");
            m3 = null;
            return m3;
        }
        System.out.println("performing matrix multiplication");
        m3 = new matrix(m1.row, m2.column);

        for(int i =0;i<m3.row;i++){
            for(int j=0;j<m3.column;j++){
                for(int k=0;k<m2.row;k++)
                m3.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
        return m3;
    }

    public static void main(String[] args) {
        System.out.println("Matrix Multiplication Programme, please enter the two matrices");
        matrix m1 = new matrix();
        m1.setMatrix();
        matrix m2 = new matrix();
        m2.setMatrix();
        matrix m3 = product(m1, m2);
        if(m3 == null){
            System.out.println("Matrix Multiplication not possible");
            return;
        }
        System.out.println("displaying product of the given matrices");
        m3.displayMatrix();
    }

}
