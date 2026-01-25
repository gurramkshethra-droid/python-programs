import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class MusicDBGUI extends JFrame {

    private Connection conn;
    private JTable table;
    private DefaultTableModel model;
    private JComboBox<String> tableSelector;
    private JPanel inputPanel;

    public MusicDBGUI() {
        setTitle("🎀 Music Database Manager ♫");
        setSize(950, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // 🌸 Step 1: Set Background Image
        ImageIcon bgImage = new ImageIcon("src/images/cute_bg.jpg");
        JLabel background = new JLabel(bgImage);
        background.setLayout(new BorderLayout());
        setContentPane(background);

        // 🌸 Transparent panels over image
        JPanel topPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        topPanel.setOpaque(false);

        JPanel centerPanel = new JPanel(new BorderLayout());
        centerPanel.setOpaque(false);

        inputPanel = new JPanel(new FlowLayout());
        inputPanel.setOpaque(false);

        // Connect to DB
        connectToDatabase();

        // ---------- TOP PANEL ----------
        topPanel.add(createStyledLabel("Select Table:"));
        tableSelector = new JComboBox<>();
        styleComboBox(tableSelector);
        topPanel.add(tableSelector);

        JButton btnLoad = createStyledButton("🎶 Load Table");
        topPanel.add(btnLoad);
        background.add(topPanel, BorderLayout.NORTH);

        // ---------- TABLE ----------
        model = new DefaultTableModel();
        table = new JTable(model);
        table.setFont(new Font("Comic Sans MS", Font.PLAIN, 14));
        table.setRowHeight(25);
        table.getTableHeader().setFont(new Font("Comic Sans MS", Font.BOLD, 15));
        table.getTableHeader().setBackground(new Color(255, 240, 245));

        JScrollPane scroll = new JScrollPane(table);
        scroll.setOpaque(false);
        scroll.getViewport().setOpaque(false);
        centerPanel.add(scroll, BorderLayout.CENTER);
        background.add(centerPanel, BorderLayout.CENTER);

        // ---------- INPUT PANEL ----------
        background.add(inputPanel, BorderLayout.SOUTH);

        // ---------- EVENTS ----------
        loadTableNames();
        btnLoad.addActionListener(e -> loadSelectedTable());
        tableSelector.addActionListener(e -> loadSelectedTable());
    }

    // ---------------- CONNECT DATABASE ----------------
    private void connectToDatabase() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/MusicDB",
                "root",
                "Ksh@#197518"
            );
            System.out.println("✅ Connected to MusicDB!");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Database connection failed: " + e.getMessage());
        }
    }

    // ---------------- LOAD TABLE NAMES ----------------
    private void loadTableNames() {
    try {
        tableSelector.removeAllItems(); // clear old ones

        // ✅ Make sure we only look inside the current database (MusicDB)
        String query = "SHOW FULL TABLES WHERE Table_type = 'BASE TABLE'";
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(query);

        while (rs.next()) {
            String tableName = rs.getString(1);
            tableSelector.addItem(tableName);
        }

        if (tableSelector.getItemCount() == 0) {
            JOptionPane.showMessageDialog(this, "No tables found in MusicDB!");
        }

    } catch (SQLException e) {
        JOptionPane.showMessageDialog(this, "Error loading table names: " + e.getMessage());
    }
}

    // ---------------- LOAD SELECTED TABLE ----------------
    private void loadSelectedTable() {
        String selectedTable = (String) tableSelector.getSelectedItem();
        if (selectedTable == null) return;

        try {
            model.setRowCount(0);
            model.setColumnCount(0);

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM " + selectedTable);
            ResultSetMetaData rsmd = rs.getMetaData();
            int columnCount = rsmd.getColumnCount();

            // Add column names
            for (int i = 1; i <= columnCount; i++) {
                model.addColumn(rsmd.getColumnName(i));
            }

            // Fill data
            while (rs.next()) {
                Object[] rowData = new Object[columnCount];
                for (int i = 1; i <= columnCount; i++) {
                    rowData[i - 1] = rs.getObject(i);
                }
                model.addRow(rowData);
            }

            // Create input fields dynamically
            createInputFields(selectedTable, rsmd);

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Error loading table: " + e.getMessage());
        }
    }

    // ---------------- CREATE INPUT FIELDS ----------------
    private void createInputFields(String tableName, ResultSetMetaData rsmd) {
        try {
            inputPanel.removeAll();
            int columnCount = rsmd.getColumnCount();
            JTextField[] textFields = new JTextField[columnCount];
            String[] columnNames = new String[columnCount];

            for (int i = 1; i <= columnCount; i++) {
                String colName = rsmd.getColumnName(i);
                columnNames[i - 1] = colName;

                if (rsmd.isAutoIncrement(i)) continue;

                inputPanel.add(createStyledLabel(colName + ":"));
                JTextField field = new JTextField(10);
                styleTextField(field);
                textFields[i - 1] = field;
                inputPanel.add(field);
            }

            JButton btnAdd = createStyledButton("➕ Add Record");
            inputPanel.add(btnAdd);

            btnAdd.addActionListener(e -> {
                try {
                    StringBuilder columns = new StringBuilder();
                    StringBuilder values = new StringBuilder();
                    int count = 0;

                    for (int i = 1; i <= columnCount; i++) {
                        if (rsmd.isAutoIncrement(i)) continue;
                        String val = textFields[i - 1].getText();
                        if (val.isEmpty()) continue;

                        if (count > 0) {
                            columns.append(", ");
                            values.append(", ");
                        }
                        columns.append(columnNames[i - 1]);
                        values.append("'").append(val).append("'");
                        count++;
                    }

                    String sql = "INSERT INTO " + tableName + " (" + columns + ") VALUES (" + values + ")";
                    Statement stmt = conn.createStatement();
                    stmt.executeUpdate(sql);

                    JOptionPane.showMessageDialog(this, "✅ Record added successfully!");
                    loadSelectedTable();

                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(this, "Error adding record: " + ex.getMessage());
                }
            });

            inputPanel.revalidate();
            inputPanel.repaint();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Error creating input fields: " + e.getMessage());
        }
    }

    // ---------------- UI STYLING HELPERS ----------------
    private JLabel createStyledLabel(String text) {
        JLabel label = new JLabel(text);
        label.setFont(new Font("Comic Sans MS", Font.BOLD, 14));
        label.setForeground(new Color(80, 40, 120));
        return label;
    }

    private JButton createStyledButton(String text) {
        JButton button = new JButton(text);
        button.setBackground(new Color(255, 182, 193)); // pastel pink
        button.setForeground(Color.WHITE);
        button.setFont(new Font("Comic Sans MS", Font.BOLD, 13));
        button.setFocusPainted(false);
        button.setBorder(BorderFactory.createEmptyBorder(5, 10, 5, 10));
        button.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        return button;
    }

    private void styleComboBox(JComboBox<String> comboBox) {
        comboBox.setFont(new Font("Comic Sans MS", Font.PLAIN, 13));
        comboBox.setBackground(new Color(255, 240, 245));
    }

    private void styleTextField(JTextField field) {
        field.setFont(new Font("Comic Sans MS", Font.PLAIN, 13));
        field.setBackground(new Color(255, 250, 250));
        field.setBorder(BorderFactory.createLineBorder(new Color(255, 192, 203), 1));
    }

    // ---------------- MAIN ----------------
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new MusicDBGUI().setVisible(true);
        });
    }
}