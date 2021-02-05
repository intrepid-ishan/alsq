import java.util.*;

class queue {
    int F, R;

    queue() {
        F = -1;
        R = -1;
    }
    void Insert_front(int x, int n, int[] arr) {
        if ((R + 1) % n == F) {
            System.out.println("QUEUE is FULL");
            return;
        }
        if (IsEmpty()) {
            F = 0;
            R = 0;
        } else if (F == 0) {
            F = n - 1;
        } else {
            F = F - 1;
        }
        arr[F] = x;
        System.out.println("Insereted value at position F(Front) = " + F + " is " + arr[F]);
    }


    void Insert_rear(int x, int n, int[] arr) {
        if ((R + 1) % n == F) {
            System.out.println("QUEUE is FULL");
            return;
        }
        if (IsEmpty()) {
            F = R = 0;
        } else {
            R = (R + 1) % n;
        }
        arr[R] = x;
        System.out.println("Insereted value at position R(rear) = " + R + " is " + arr[R]);
    }

    void Delete_front(int n, int[] arr) {
        if (IsEmpty()) {
            System.out.println("QUEUE is EMPTY");
        }
        if (F == R) {
            System.out.println("Deleted value from F(front)" + F + " is " + arr[F]);
            F = -1;
            R = -1;
        } else {
            System.out.println("Deleted value from " + F + " is " + arr[F]);
            F = (F + 1) % n;
        }
    }

    void Delete_rear(int n, int[] arr) {
        if (IsEmpty()) {
            System.out.println("Queue is empty");
        }
        if (F == R) {
            System.out.println("Deleted value from R(rear)" + R + " is " + arr[R]);
            F = -1;
            R = -1;
        } else {
            System.out.println("Deleted value from R(rear)" + R + " is " + arr[R]);
            R = R + 1 % n;
        }
    }

    void Front(int[] arr) {
        if (IsEmpty()) {
            System.out.println("Queue is empty");
            return;
        } else {
            System.out.println("Value at front is" + arr[F]);
        }
    }


    void PrintQ(int n, int[] arr) {
        int count = (R + n - F) % n + 1;
        System.out.println("Queue       : ");
        for (int i = 0; i < count; i++) {
            int index = (F + i) % n;
            System.out.print(" " + arr[index]);
        }
        System.out.println(" ");
    }


    boolean IsEmpty() {
        return (F == -1 && R == -1);
    }

    boolean IsFull() {
        return (F == R);
    }
}
class App {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array:");
        int n = sc.nextInt();
        int arr[] = new int[n];
        queue q = new queue();

        while (true) {
            System.out.println("1 Insert_rear ");
            System.out.println("2 Delete_front ");
            System.out.println("3 Insert_front ");
            System.out.println("4 Delete_rear ");
            System.out.println("5 Get Front ");
            System.out.println("6 Print ");
            int choice;
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Please enter the integer to be inserted in rear");
                    int value1 = sc.nextInt();
                    q.Insert_rear(value1, n, arr);
                    break;
                case 2:
                    try {
                        q.Delete_front(n, arr);
                        break;
                    } catch (Exception e) {
                        System.out.println("ArrayIndexOutOfBoundException");
                    }
                    continue;
                case 3:
                    System.out.println("Please enter the integer to be inserted in front");
                    int value2 = sc.nextInt();
                    q.Insert_front(value2, n, arr);
                    break;
                case 4:
                    try {
                        q.Delete_rear(n, arr);
                        break;
                    } catch (Exception e) {
                        System.out.println("ArrayIndexOutOfBoundException");
                    }
                    continue;
                case 5:
                    q.Front(arr);
                    break;
                case 6:
                    q.PrintQ(n, arr);
                    break;
            }
        }
    }
}