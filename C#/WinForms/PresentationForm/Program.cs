using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsPresentationApp
{
    public partial class PresentationForm : Form
    {
        private int currentSlideIndex = 0;
        private List<Slide> slides;
        private Panel slidePanel;
        private Panel navigationPanel;
        private Label slideCounterLabel;
        private Button prevButton, nextButton, fullscreenButton;

        public PresentationForm()
        {
            InitializeComponent();
            InitializeSlides();
            SetupUI();
            ShowSlide(0);
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();

            // Form properties
            this.AutoScaleDimensions = new SizeF(8F, 16F);
            this.AutoScaleMode = AutoScaleMode.Font;
            this.ClientSize = new Size(1920, 1080);
            this.FormBorderStyle = FormBorderStyle.None;
            this.WindowState = FormWindowState.Maximized;
            this.StartPosition = FormStartPosition.CenterScreen;
            this.Text = "Windows Forms Applications with C# & VS 2022";
            this.BackColor = Color.FromArgb(102, 126, 234);
            this.KeyPreview = true;

            this.ResumeLayout(false);
        }

        private void SetupUI()
        {
            // Create gradient background
            this.Paint += (s, e) =>
            {
                using (LinearGradientBrush brush = new LinearGradientBrush(
                    this.ClientRectangle,
                    Color.FromArgb(102, 126, 234),
                    Color.FromArgb(118, 75, 162),
                    LinearGradientMode.Vertical))
                {
                    e.Graphics.FillRectangle(brush, this.ClientRectangle);
                }
            };

            // Main slide panel
            slidePanel = new Panel
            {
                Size = new Size(1720, 900),
                Location = new Point(100, 50),
                BackColor = Color.White,
                BorderStyle = BorderStyle.None
            };

            // Add rounded corners effect
            slidePanel.Paint += (s, e) =>
            {
                using (GraphicsPath path = CreateRoundedRectanglePath(slidePanel.ClientRectangle, 20))
                {
                    slidePanel.Region = new Region(path);
                    e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
                    using (SolidBrush brush = new SolidBrush(Color.White))
                    {
                        e.Graphics.FillPath(brush, path);
                    }
                }
            };

            // Navigation panel
            navigationPanel = new Panel
            {
                Size = new Size(400, 60),
                Location = new Point(760, 980),
                BackColor = Color.Transparent
            };

            // Navigation buttons
            prevButton = CreateNavigationButton("← Previous", new Point(0, 0));
            nextButton = CreateNavigationButton("Next →", new Point(140, 0));
            fullscreenButton = CreateNavigationButton("Toggle FS", new Point(280, 0));

            prevButton.Click += (s, e) => PreviousSlide();
            nextButton.Click += (s, e) => NextSlide();
            fullscreenButton.Click += (s, e) => ToggleFullscreen();

            // Slide counter
            slideCounterLabel = new Label
            {
                Size = new Size(100, 30),
                Location = new Point(1750, 70),
                BackColor = Color.FromArgb(102, 126, 234),
                ForeColor = Color.White,
                TextAlign = ContentAlignment.MiddleCenter,
                Font = new Font("Segoe UI", 10, FontStyle.Bold)
            };
            slideCounterLabel.Paint += (s, e) =>
            {
                using (GraphicsPath path = CreateRoundedRectanglePath(slideCounterLabel.ClientRectangle, 15))
                {
                    slideCounterLabel.Region = new Region(path);
                }
            };

            navigationPanel.Controls.AddRange(new Control[] { prevButton, nextButton, fullscreenButton });
            this.Controls.AddRange(new Control[] { slidePanel, navigationPanel, slideCounterLabel });

            // Keyboard events
            this.KeyDown += PresentationForm_KeyDown;
        }

        private Button CreateNavigationButton(string text, Point location)
        {
            var button = new Button
            {
                Text = text,
                Size = new Size(120, 40),
                Location = location,
                BackColor = Color.FromArgb(240, 240, 240),
                FlatStyle = FlatStyle.Flat,
                Font = new Font("Segoe UI", 9),
                Cursor = Cursors.Hand
            };

            button.FlatAppearance.BorderSize = 0;
            button.Paint += (s, e) =>
            {
                using (GraphicsPath path = CreateRoundedRectanglePath(button.ClientRectangle, 20))
                {
                    button.Region = new Region(path);
                }
            };

            return button;
        }

        private GraphicsPath CreateRoundedRectanglePath(Rectangle rectangle, int radius)
        {
            GraphicsPath path = new GraphicsPath();
            int diameter = radius * 2;
            Size size = new Size(diameter, diameter);
            Rectangle arc = new Rectangle(rectangle.Location, size);

            // Top left arc
            path.AddArc(arc, 180, 90);

            // Top right arc
            arc.X = rectangle.Right - diameter;
            path.AddArc(arc, 270, 90);

            // Bottom right arc
            arc.Y = rectangle.Bottom - diameter;
            path.AddArc(arc, 0, 90);

            // Bottom left arc
            arc.X = rectangle.Left;
            path.AddArc(arc, 90, 90);

            path.CloseFigure();
            return path;
        }

        private void InitializeSlides()
        {
            slides = new List<Slide>
            {
                new Slide
                {
                    Title = "Windows Forms Applications",
                    Subtitle = "Building Desktop GUIs with C# & Visual Studio 2022",
                    Content = new[]
                    {
                        "Learning Outcomes:",
                        "• Understand Windows Forms architecture and components",
                        "• Create and configure a WinForms project in VS 2022",
                        "• Design interfaces using drag-and-drop controls",
                        "• Handle events and implement user interactions",
                        "• Build a complete CRUD application with data binding",
                        "• Deploy and distribute your desktop applications",
                        "",
                        "What We'll Cover:",
                        "• WinForms fundamentals",
                        "• Visual Studio 2022 setup",
                        "• Form designer and controls",
                        "• Event handling and code-behind",
                        "",
                        "Practical Skills:",
                        "• Data binding techniques",
                        "• Error handling and validation",
                        "• Application deployment",
                        "• Best practices and tips"
                    }
                },
                new Slide
                {
                    Title = "Why Choose Windows Forms?",
                    Subtitle = "Understanding the advantages and use cases",
                    Content = new[]
                    {
                        "Key Advantages:",
                        "",
                        "🎨 Rapid GUI Design",
                        "Drag-and-drop interface builder with instant visual feedback.",
                        "Perfect for quick prototyping and development.",
                        "",
                        "🏗️ Mature Framework",
                        "Decades of development and optimization.",
                        "Extensive .NET Framework and .NET Core support.",
                        "",
                        "💼 Business Applications",
                        "Ideal for small to medium desktop utilities, database front-ends,",
                        "and internal business tools.",
                        "",
                        "🔗 Easy Integration",
                        "Seamless interoperability with other .NET libraries,",
                        "databases, and third-party components.",
                        "",
                        "✅ Great For:",
                        "• Database management tools",
                        "• System utilities and admin tools",
                        "• Legacy application modernization",
                        "• Rapid internal business applications",
                        "• Simple data entry forms"
                    }
                },
                new Slide
                {
                    Title = "Anatomy of a WinForms Application",
                    Subtitle = "Understanding the core components and file structure",
                    Content = new[]
                    {
                        "📁 Key Files:",
                        "",
                        "Program.cs - Application entry point",
                        "static void Main()",
                        "{",
                        "    Application.EnableVisualStyles();",
                        "    Application.SetCompatibleTextRenderingDefault(false);",
                        "    Application.Run(new MainForm());",
                        "}",
                        "",
                        "Form1.cs - Main form class (inherits from System.Windows.Forms.Form)",
                        "public partial class Form1 : Form",
                        "{",
                        "    public Form1()",
                        "    {",
                        "        InitializeComponent();",
                        "    }",
                        "}",
                        "",
                        "Form1.Designer.cs - Auto-generated control layout and properties",
                        "Form1.resx - Resource file for images, strings, and other resources",
                        "",
                        "🔍 Important Notes:",
                        "• Partial Classes: Form code is split across multiple files",
                        "• Designer Generated: Never manually edit .Designer.cs",
                        "• Resources: Images and strings stored in .resx files"
                    }
                },
                new Slide
                {
                    Title = "Setting Up Visual Studio 2022",
                    Subtitle = "Configuring your development environment",
                    Content = new[]
                    {
                        "🛠️ Required Components:",
                        "",
                        "1. Install \".NET desktop development\" workload",
                        "   • Open Visual Studio Installer",
                        "   • Select \"Modify\" for your VS 2022 installation",
                        "   • Check \".NET desktop development\" workload",
                        "",
                        "2. Ensure .NET Framework/Core is available",
                        "   • .NET 6/7/8 (recommended for new projects)",
                        "   • .NET Framework 4.7.2 or higher (for legacy compatibility)",
                        "",
                        "3. Enable WinForms Designer extensions",
                        "   • Individual components → Windows Forms Designer",
                        "   • IntelliCode for enhanced development experience",
                        "",
                        "✅ Verification Checklist:",
                        "• Toolbox shows Windows Forms controls",
                        "• Form Designer opens without errors",
                        "• Project templates include \"Windows Forms App\"",
                        "• Properties window displays control properties",
                        "",
                        "💡 Pro Tips:",
                        "• Install latest VS 2022 updates for best stability",
                        "• Enable \"Preview Features\" for cutting-edge tools",
                        "• Consider Git for Windows for version control"
                    }
                },
                new Slide
                {
                    Title = "Creating a New WinForms Project",
                    Subtitle = "Step-by-step project creation guide",
                    Content = new[]
                    {
                        "🚀 Project Creation Steps:",
                        "",
                        "1. Start New Project",
                        "   • File → New → Project (or Ctrl+Shift+N)",
                        "   • Search for \"Windows Forms App\" template",
                        "   • Select the C# version",
                        "",
                        "2. Configure Project",
                        "   • Project name: MyWinFormsApp",
                        "   • Location: Choose appropriate directory",
                        "   • Solution name: Usually same as project",
                        "",
                        "3. Select Framework",
                        "   • .NET 6/7/8: Modern, cross-platform",
                        "   • .NET Framework 4.8: Windows-only, maximum compatibility",
                        "",
                        "4. Explore Solution Structure",
                        "   • Dependencies (NuGet packages and frameworks)",
                        "   • Form1.cs (main form)",
                        "   • Program.cs (entry point)",
                        "",
                        "📋 Project Settings (in .csproj):",
                        "<Project Sdk=\"Microsoft.NET.Sdk\">",
                        "  <PropertyGroup>",
                        "    <OutputType>WinExe</OutputType>",
                        "    <TargetFramework>net6.0-windows</TargetFramework>",
                        "    <UseWindowsForms>true</UseWindowsForms>",
                        "  </PropertyGroup>",
                        "</Project>"
                    }
                },
                new Slide
                {
                    Title = "The Form Designer",
                    Subtitle = "Visual interface design and control management",
                    Content = new[]
                    {
                        "🧰 Toolbox Controls:",
                        "",
                        "Common Controls:",
                        "• Button, Label, TextBox",
                        "• CheckBox, RadioButton",
                        "• ListBox, ComboBox",
                        "",
                        "Data Controls:",
                        "• DataGridView",
                        "• BindingSource",
                        "• DataSet, DataTable",
                        "",
                        "Containers:",
                        "• Panel, GroupBox",
                        "• TabControl",
                        "• SplitContainer",
                        "",
                        "⚙️ Key Properties to Master:",
                        "• Name: Identifier in code (btnSave, txtName)",
                        "• Text: Visible label or content",
                        "• Size: Width and height in pixels",
                        "• Location: X, Y coordinates",
                        "• Anchor: Resizing behavior",
                        "• Dock: Edge attachment",
                        "• Enabled: User interaction state",
                        "• Visible: Display state",
                        "",
                        "🎯 Design Best Practices:",
                        "• Use consistent spacing (6, 12, 24 pixels)",
                        "• Align controls to grid lines",
                        "• Group related controls in containers",
                        "• Set meaningful control names"
                    }
                },
                new Slide
                {
                    Title = "Writing Code Behind",
                    Subtitle = "Event handling and user interaction",
                    Content = new[]
                    {
                        "🎯 Event Handling:",
                        "",
                        "Quick Event Generation:",
                        "Double-click any control to auto-generate its default event handler",
                        "",
                        "private void btnClickMe_Click(object sender, EventArgs e)",
                        "{",
                        "    lblStatus.Text = \"Hello, WinForms!\";",
                        "    MessageBox.Show(\"Button clicked!\");",
                        "}",
                        "",
                        "Common Event Types:",
                        "• Click: Button presses, menu selections",
                        "• TextChanged: TextBox content updates",
                        "• SelectedIndexChanged: ListBox/ComboBox selection",
                        "• FormClosing: Window close prevention/cleanup",
                        "• Load: Form initialization",
                        "",
                        "🔧 Control Access Patterns:",
                        "",
                        "// Strongly-typed field access (recommended)",
                        "private void btnSave_Click(object sender, EventArgs e)",
                        "{",
                        "    string username = txtUsername.Text;",
                        "    if (string.IsNullOrEmpty(username))",
                        "    {",
                        "        MessageBox.Show(\"Please enter a username\");",
                        "        return;",
                        "    }",
                        "    SaveUser(username);",
                        "}"
                    }
                },
                new Slide
                {
                    Title = "Data Binding & CRUD Operations",
                    Subtitle = "Building a complete data management interface",
                    Content = new[]
                    {
                        "👥 Complete CRUD Example:",
                        "",
                        "public partial class PersonManagerForm : Form",
                        "{",
                        "    private List<Person> people = new List<Person>();",
                        "    private BindingSource bindingSource = new BindingSource();",
                        "    ",
                        "    public PersonManagerForm()",
                        "    {",
                        "        InitializeComponent();",
                        "        SetupDataBinding();",
                        "        LoadSampleData();",
                        "    }",
                        "",
                        "    private void SetupDataBinding()",
                        "    {",
                        "        bindingSource.DataSource = people;",
                        "        dataGridView1.DataSource = bindingSource;",
                        "        ",
                        "        // Bind individual controls",
                        "        txtName.DataBindings.Add(\"Text\", bindingSource, \"Name\");",
                        "        txtEmail.DataBindings.Add(\"Text\", bindingSource, \"Email\");",
                        "    }",
                        "}",
                        "",
                        "➕ Create Operation:",
                        "private void btnAdd_Click(object sender, EventArgs e)",
                        "{",
                        "    var person = new Person { Name = txtNewName.Text };",
                        "    people.Add(person);",
                        "    bindingSource.ResetBindings(false);",
                        "}"
                    }
                },
                new Slide
                {
                    Title = "Error Handling & Validation",
                    Subtitle = "Building robust and user-friendly applications",
                    Content = new[]
                    {
                        "🛡️ Input Validation:",
                        "",
                        "private bool ValidateForm()",
                        "{",
                        "    var errors = new List<string>();",
                        "    ",
                        "    if (string.IsNullOrWhiteSpace(txtName.Text))",
                        "        errors.Add(\"Name is required\");",
                        "        ",
                        "    if (!IsValidEmail(txtEmail.Text))",
                        "        errors.Add(\"Valid email is required\");",
                        "    ",
                        "    if (errors.Any())",
                        "    {",
                        "        MessageBox.Show(string.Join(\"\\n\", errors),",
                        "            \"Validation Errors\",",
                        "            MessageBoxButtons.OK,",
                        "            MessageBoxIcon.Warning);",
                        "        return false;",
                        "    }",
                        "    return true;",
                        "}",
                        "",
                        "⚠️ Error Provider Control:",
                        "Use ErrorProvider control for real-time validation feedback",
                        "",
                        "🎯 Validation Best Practices:",
                        "• Validate on focus lost (Validating event)",
                        "• Provide immediate visual feedback",
                        "• Use clear, helpful error messages",
                        "• Prevent form submission with invalid data"
                    }
                },
                new Slide
                {
                    Title = "Deploying Your Application",
                    Subtitle = "Distribution and installation options",
                    Content = new[]
                    {
                        "Deployment Options:",
                        "",
                        "📁 Folder Deployment",
                        "Simplest method: Copy executable and dependencies",
                        "• Right-click project → Publish",
                        "• Choose \"Folder\" target",
                        "• Self-contained or framework-dependent",
                        "• Creates ready-to-run directory",
                        "",
                        "🌐 ClickOnce Deployment",
                        "Web-based installation: Automatic updates",
                        "• Hosted on web server or network share",
                        "• Automatic update checks",
                        "• Security sandbox restrictions",
                        "• Easy user installation",
                        "",
                        "📦 MSI Installer",
                        "Professional deployment: Windows Installer",
                        "• Visual Studio Installer Projects extension",
                        "• Custom installation dialogs",
                        "• Registry and file associations",
                        "• Uninstall support",
                        "",
                        "🏪 Microsoft Store",
                        "Modern distribution: Windows Package (.msix)",
                        "• Automatic updates",
                        "• Secure installation",
                        "• Wide distribution reach"
                    }
                },
                new Slide
                {
                    Title = "Best Practices & Professional Tips",
                    Subtitle = "Writing maintainable and performant WinForms applications",
                    Content = new[]
                    {
                        "🏗️ Architecture Patterns:",
                        "",
                        "Separation of Concerns:",
                        "// Business Logic Layer",
                        "public class PersonService",
                        "{",
                        "    public List<Person> GetAllPersons() { /* ... */ }",
                        "    public void SavePerson(Person person) { /* ... */ }",
                        "}",
                        "",
                        "// Form (Presentation Layer)",
                        "public partial class PersonForm : Form",
                        "{",
                        "    private PersonService _service = new();",
                        "    ",
                        "    private void LoadData()",
                        "    {",
                        "        var persons = _service.GetAllPersons();",
                        "        bindingSource.DataSource = persons;",
                        "    }",
                        "}",
                        "",
                        "⚡ Performance Optimization:",
                        "• Use async operations for responsiveness",
                        "• Implement background workers for heavy tasks",
                        "• Dispose resources properly",
                        "• Avoid memory leaks with event handlers",
                        "",
                        "🎯 Code Organization:",
                        "• Use meaningful naming conventions",
                        "• Separate business logic from UI",
                        "• Implement proper error handling",
                        "• Create testable, maintainable code"
                    }
                },
                new Slide
                {
                    Title = "Resources & Next Steps",
                    Subtitle = "Continue your Windows Forms journey",
                    Content = new[]
                    {
                        "📚 Learning Resources:",
                        "",
                        "Official Documentation:",
                        "• Microsoft Docs: Windows Forms overview",
                        "• API Reference: System.Windows.Forms namespace",
                        "• .NET Application Architecture: Best practices guides",
                        "",
                        "Online Courses:",
                        "• Pluralsight: Windows Forms development courses",
                        "• Udemy: C# Windows Forms from scratch",
                        "• Microsoft Learn: Free learning paths",
                        "",
                        "Community & Support:",
                        "• Stack Overflow: Q&A and problem solving",
                        "• GitHub: Sample repositories and open source",
                        "• Reddit: r/csharp and r/dotnet communities",
                        "",
                        "🎯 Practice Projects:",
                        "",
                        "🏠 Homework Assignment:",
                        "Build a \"Personal Task Manager\" application with:",
                        "1. Task creation with title, description, due date",
                        "2. Priority levels (High, Medium, Low) with color coding",
                        "3. Mark tasks as complete/incomplete",
                        "4. Edit and delete existing tasks",
                        "5. Search and filter functionality",
                        "6. Save data to XML or JSON file",
                        "",
                        "🎓 Thank You!",
                        "Ready to build amazing desktop applications!"
                    }
                }
            };
        }

        private void ShowSlide(int index)
        {
            if (index < 0 || index >= slides.Count) return;

            currentSlideIndex = index;
            slideCounterLabel.Text = $"{index + 1} / {slides.Count}";

            slidePanel.Controls.Clear();

            var slide = slides[index];

            // Title
            var titleLabel = new Label
            {
                Text = slide.Title,
                Font = new Font("Segoe UI", 32, FontStyle.Bold),
                ForeColor = Color.FromArgb(102, 126, 234),
                Size = new Size(1600, 60),
                Location = new Point(60, 40),
                TextAlign = ContentAlignment.MiddleCenter
            };

            // Subtitle
            var subtitleLabel = new Label
            {
                Text = slide.Subtitle,
                Font = new Font("Segoe UI", 18, FontStyle.Regular),
                ForeColor = Color.FromArgb(102, 102, 102),
                Size = new Size(1600, 40),
                Location = new Point(60, 100),
                TextAlign = ContentAlignment.MiddleCenter
            };

            // Content area with scrolling
            var contentPanel = new Panel
            {
                Size = new Size(1600, 720),
                Location = new Point(60, 160),
                AutoScroll = true,
                BackColor = Color.White
            };

            // Content text
            var contentText = string.Join(Environment.NewLine, slide.Content);
            var contentLabel = new Label
            {
                Text = contentText,
                Font = new Font("Segoe UI", 14, FontStyle.Regular),
                ForeColor = Color.FromArgb(51, 51, 51),
                Size = new Size(1580, 2000), // Large height for auto-sizing
                Location = new Point(10, 10),
                AutoSize = false,
                TextAlign = ContentAlignment.TopLeft
            };

            // Calculate actual height needed
            using (Graphics g = contentLabel.CreateGraphics())
            {
                var size = g.MeasureString(contentText, contentLabel.Font, 1580);
                contentLabel.Height = (int)Math.Ceiling(size.Height) + 20;
            }

            contentPanel.Controls.Add(contentLabel);
            slidePanel.Controls.AddRange(new Control[] { titleLabel, subtitleLabel, contentPanel });

            // Update navigation buttons
            prevButton.Enabled = currentSlideIndex > 0;
            nextButton.Enabled = currentSlideIndex < slides.Count - 1;
        }

        private void NextSlide()
        {
            if (currentSlideIndex < slides.Count - 1)
                ShowSlide(currentSlideIndex + 1);
        }

        private void PreviousSlide()
        {
            if (currentSlideIndex > 0)
                ShowSlide(currentSlideIndex - 1);
        }

        private void ToggleFullscreen()
        {
            if (this.FormBorderStyle == FormBorderStyle.None)
            {
                this.FormBorderStyle = FormBorderStyle.Sizable;
                this.WindowState = FormWindowState.Normal;
            }
            else
            {
                this.FormBorderStyle = FormBorderStyle.None;
                this.WindowState = FormWindowState.Maximized;
            }
        }

        private void PresentationForm_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Right:
                case Keys.Space:
                    NextSlide();
                    break;
                case Keys.Left:
                    PreviousSlide();
                    break;
                case Keys.F11:
                    ToggleFullscreen();
                    break;
                case Keys.Escape:
                    this.Close();
                    break;
                case Keys.Home:
                    ShowSlide(0);
                    break;
                case Keys.End:
                    ShowSlide(slides.Count - 1);
                    break;
            }
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            var result = MessageBox.Show("Are you sure you want to exit the presentation?",
                "Exit Presentation", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.No)
                e.Cancel = true;

            base.OnFormClosing(e);
        }
    }

    public class Slide
    {
        public string Title { get; set; }
        public string Subtitle { get; set; }
        public string[] Content { get; set; }
    }

    // Program.cs
    public class Program
    {
        [STAThread]
        public static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new PresentationForm());
        }
    }
}