"""
Format Simulator Peripheral Support CSV file into HTML file

input file (csv/text):
    periphcoveragemgr.txt

output files (html,csv):
    SimPeripheralSupport.html
    SimPeripheralSupport.csv

"""

# Imports
import csv
import datetime
import device_info_log
import traceback
import sys

# Global Variables
csv_data = []

#
# Functions
#

# HTML file header
def output_html_header(output):
    html_title = "Simulator Peripheral Support by Device (BETA)"
    
    output.write("<html>\n")
    output.write("<head>\n")
    output.write("  <title>" + html_title + "</title>\n")

    output.write("  <style type=\"text/css\">\n")
    output.write("    th.rotate {\n")
    output.write("      height: 180px;\n")
    output.write("      white-space: nowrap;\n")
    output.write("      background-color: lightblue;\n")
    output.write("    }\n")
    output.write("    th.rotate > div {\n")
    output.write("      transform:\n")
    output.write("        translate(0px, 75px)\n")
    output.write("        rotate(-90deg);\n")
    output.write("      width: 30px;\n")
    output.write("    }\n")
    output.write("    th.rotate > div > span {\n")
    output.write("      border-bottom: 1px solid #ccc;\n")
    output.write("      padding: 5px 10px;\n")
    output.write("    }\n")
    output.write("    th.row-header {\n")
    output.write("      background-color: lightblue;\n")
    output.write("      text-align: left;\n")
    output.write("    }\n")
    output.write("    td {\n")
    output.write("      text-align: center;\n")
    output.write("    }\n")
    output.write("  </style>\n")

    output.write("</head>\n")
    output.write("\n")
    output.write("<body style=\"font-family:sans-serif; font-size:10pt\" bgcolor=\"#FFFFE0\">\n")
    output.write("\n")
    output.write("<h1>" + html_title + "</h1>\n")    
    output.write("<p style=\"font-size:12pt\">Information taken from MPLAB X IDE device database files.</p>\n")
    output.write("<p style=\"font-size:12pt\"><b>Table Headings:</b> " +
                      "To see a list of heading descriptions, click <a href=\"SimPeriphSupportInfo.html\">here</a>.<br>" +
                      "<b>Table Cells:</b> Mouse over a supported table cell to see the associated device. " +
                      "To sort the data, use the CSV file (<a href=\"SimPeripheralSupport.csv\">SimPeripheralSupport.csv</a>).</p>\n")
    output.write("<p style=\"font-size:12pt\"><b>Color Legend:</b> " +
                      "<i>Green cells:</i> supported; " +
                      "<i>Gray cells:</i> no support.<br>"
                      "<b>Text Legend:</b> " +
                      "<i>X:</i> supported; " +
                      "<i>Blank:</i> no support.</p>\n")                 
    output.write("<p></p>\n")
    
    return

# Table Header Row
def output_table_header(output, periph_list):

    output.write("  <tr>\n")
    
    # First cell is empty
    empty_cell = True

    for periph in periph_list:
        if empty_cell:
            output.write("    <th></th>\n")
            empty_cell = False
        else:
            output.write("    <th class=\"rotate\"><div><span>" + periph + "</span></div></th>\n")

    output.write("  </tr>\n")
    
    return

# Table Body Rows
def output_table_row(output, support_list):

    output.write("  <tr>\n")
    
    # First cell contains device name
    device = ""
    device_cell = True

    for support in support_list:
        if device_cell:
            device = support
            output.write("    <th class=\"row-header\">" + device + "</th>\n")
            device_cell = False
        else:
            if support == "X":
                bgcolor = "palegreen"
            else:
                bgcolor = "lightgray"
            
            output.write("    <td bgcolor=\"" + bgcolor + "\";><span title=\"" + device + "\">" + support + "</span></td>\n")

    output.write("  </tr>\n")
    
    return

# HTML file footer
def output_html_footer(output):

    # Date stamp
    today = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    output.write("<p></p>\n")
    output.write(today + "\n")

    # End HTML file
    output.write("</body>\n")
    output.write("</html>\n")
    
    return

# Read CSV file data, clean, write out
def read_write_csv():

    # Read in CSV data and clean up
    with open('periphcoveragemgr.txt', 'rb') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=',')
        for row in csvreader:
            # ignore device exceptions
            if len(row) > 2:
                # get rid of end empty element
                del row[-1]
                # add to list
                csv_data.append(row)

    #print "Number of devices: " + str(len(csv_data)-1)

    # Write out modified CSV data
    with open('SimPeripheralSupport.csv', 'wb') as csvfile:
        csvwriter = csv.writer(csvfile, delimiter=',')
        for row in csv_data:
            csvwriter.writerow(row)
            
    return

# Print out data in HTML format
def output2html():

    # Open HTML file and write header
    html_out = open("SimPeripheralSupport.html", "w")
    output_html_header(html_out)

    # Begin table
    html_out.write("<table class=\"table table-header-rotated\">\n")

    # Grab header row for repeating
    table_header = csv_data[0]
    del csv_data[0]
    output_table_header(html_out,table_header)

    # Init heading repeat variables
    n = 0
    repeat_cnt = 15

    # Write out rows of data
    for row in csv_data:

        if n < repeat_cnt:
            n += 1
        else:
            output_table_header(html_out,table_header)
            n = 0

        output_table_row(html_out,row)

    # End table
    html_out.write("</table>\n")

    # End and close HTML file
    output_html_footer(html_out)
    html_out.close()

#
# Main Program
#

try:
    read_write_csv()
    output2html()
except Exception:
    print("SimPeriphSupport:CSV2HTML: Exception Occurred")
    device_info_log.log_error("SimPeriphSupport_CSV2HTML", traceback.format_exc())
    sys.exit(0)
