import java.util.Scanner;

class Sol {
    private int[] id;

    public void QuickFindUF(final int n) {
        id = new int[n];
        for (int i = 0; i < n; ++i)
            id[i] = i;
    }

    public boolean connected(final int p, final int q) {
        return id[p] == id[q];
    }

    public void union(final int p, final int q) {
        final int pid = id[p];
        final int qid = id[q];
        for (int i = 0; i < id.length; ++i)
            if (id[i] == pid)
                id[i] = qid;
    }

    public static void main(final String[] args) {
        int n = StdIn.readInt();
    }
}