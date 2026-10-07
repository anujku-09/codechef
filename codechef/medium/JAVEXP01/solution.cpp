        while (!scanner.hasNextInt()) { System.out.print(p); scanner.next(); }
        int v = scanner.nextInt(); scanner.nextLine(); return v;
    }
    private double readDouble(String p) {
        System.out.print(p);
        while (!scanner.hasNextDouble()) { System.out.print(p); scanner.next(); }
        double v = scanner.nextDouble(); scanner.nextLine(); return v;
    }
    private String readLine(String p) {
        System.out.print(p);
        return scanner.nextLine();
    }
}
