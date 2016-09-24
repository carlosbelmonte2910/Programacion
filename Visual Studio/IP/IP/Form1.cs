using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private bool preventCaching = false;  

        public Form1()
        {
            InitializeComponent();
        }
        
        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                this.pictureBox1.Image = this.GetSingleFrame(@"http://192.168.1.7/video.mjpg?mute");
            }
        }
        public Bitmap GetSingleFrame(string source)
        {
            byte[] buffer = new byte[640 * 480];   // buffer to read stream
            HttpWebRequest req = null;
            WebResponse resp = null;
            Stream stream = null;
            Random rnd = new Random((int)DateTime.Now.Ticks);

            try
            {
                int read, total = 0;

                // create request
                if (!preventCaching)
                {
                    req = (HttpWebRequest)WebRequest.Create(source);
                }
                else
                {
                    req = (HttpWebRequest)WebRequest.Create(source + ((source.IndexOf('?') == -1) ? '?' : '&') + "fake=" + rnd.Next().ToString());
                }
                // set login and password                
                req.Credentials = new NetworkCredential("admin", "admin");

                req.Timeout = -1;

                resp = req.GetResponse();

                // get response stream
                stream = resp.GetResponseStream();

                // loop
                do
                {
                    read = stream.Read(buffer, total, 1024);

                    total += read;
                }
                while (read != 0);

                Bitmap bmp = (Bitmap)Bitmap.FromStream(new MemoryStream(buffer, 0, total));

                return bmp;
            }
            catch (WebException ex)
            {
                string s = ex.ToString();
                return null;
            }
            catch (Exception ex)
            {
                string s = ex.ToString();
                return null;
            }
            finally
            {
                // abort request
                if (req != null)
                {
                    req.Abort();
                    req = null;
                }
                // close response stream
                if (stream != null)
                {
                    stream.Close();
                    stream = null;
                }
                // close response
                if (resp != null)
                {
                    resp.Close();
                    resp = null;
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.backgroundWorker1.RunWorkerAsync();
        }
    }
}
