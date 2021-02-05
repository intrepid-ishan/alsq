import java.util.*;

class queue {

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr[] = new int[n];
    int F, R;

    queue() {
        F = -1;
        R = -1;
    }

    void Insert(int item) {

        if (IsFull()) {
            System.out.println("QUEUE is FULL");
            return;
        }
        if (F == -1) {
            System.out.println("The value of  F=" + F);
            System.out.println("The value of  R=" + R);
            F = R = 0;
            System.out.println("The value after insertion of  F=" + F);
            System.out.println("The value after insertion of  R=" + R);
        } else {
            System.out.println("Value of R before insertion is: " + R);
            R = (R + 1) % n;
            System.out.println("Value of R after insertion is: " + R);
        }
        try {
            arr[R] = item;

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundException");
        }
    }

    void Delete() {

        if (IsEmpty()) {
            System.out.println("QUEUE is EMPTY");
        }

        if (F == R) {
            F = -1;
            R = -1;
        } else {
            System.out.println("Value of F before deletion is: " + F);
            int item = arr[F];
            System.out.println("Deleted element is " + item);
            F = (F + 1) % n;
            System.out.println("Value of F after deletion is: " + F);
        }

    }

    void Front() {
        if (IsEmpty()) {
            System.out.println("Queue is empty");
            return;
        } else {
            System.out.println(arr[F]);
        }
    }

    void PrintQ() {

        int count = (R + n - F) % n + 1;
        System.out.println("Queue       : ");
        for (int i = 0; i < count; i++) {
            int index = (F + i) % n;
            try {
                System.out.print(arr[index]);
            } catch (Exception e) {
                System.out.println("Empty not able to print");
            }
        }

        System.out.println(" ");
    }


    boolean IsEmpty() {
        if (F == -1) return true;
        else return false;
    }

    boolean IsFull() {
        if (F == 0 && R == n - 1 || F == R + 1) return true;
        else return false;
    }
}


class App {
    public static void main(String args[]) throws Exception {
        System.out.println("please enter the valid size of an queue");
        Scanner scanner = new Scanner(System.in);
        queue q = new queue();


        while (true) {
            System.out.println("1.Insert\n");
            System.out.println("2.Delete\n");
            System.out.println("3.Display element at the front\n");
            System.out.println("4.Display all elements of the queue\n");
            System.out.println("5.Quit\n");
            System.out.println("Enter your choice between 1 and 5 : ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Input the element for adding in queue : ");
                    int item = scanner.nextInt();
                    q.Insert(item);
                    break;
                case 2:
                    q.Delete();

                    break;
                case 3:
                    q.Front();
                    break;
                case 4:
                    q.PrintQ();
                    break;
                case 5:

                default:
                    System.out.println("Wrong choice\n");
            }
        }

    }
}