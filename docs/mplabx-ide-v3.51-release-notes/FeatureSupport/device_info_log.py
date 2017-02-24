"""
Log errors from device info related files.

"""

# Imports
import datetime

# Check for exception error from modules
# If true, log or print, and exit program gracefully
def log_error(mod_name, err_text):

    # Try to open and write log file
    try:
        log_file = open(mod_name + ".log", "w")

        # Date stamp
        today = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_file.write("Log file created: " + today + "\n")

        # Error content
        log_file.write(err_text)

        log_file.close()

    except Exception:
        print "Log file can't be opened/written"
        print err_text

    return
