import sys
import subprocess
import glob
from datetime import datetime
import xml.etree.ElementTree as ET

# run the Unity tests that have been compiled, output the results in a format Jenkins can recognise

# basically, find all .exe files that start with the word "test", run each, get the output



if __name__ == "__main__":

    if len(sys.argv) == 2:
        exe_directory = sys.argv[1]
    else:
        exe_directory = "build/"

    # get all test exe's
    test_files = glob.glob("{}test*.exe".format(exe_directory))

    now = datetime.now()
    timestamp = "{year}{month:02d}{day:02d}_{hour:02d}{min:02d}{sec:02d}".format(
        year=now.year, month=now.month, day=now.day, hour=now.hour, min=now.minute, sec=now.second
    )
    xml_root = ET.Element("testsuites", attrib={"id":timestamp})
    for test in test_files:
        print("Running {}".format(test))
        output = subprocess.run(test, capture_output=True, text=True)
        print("Received Output:\n{}".format(output.stdout))
        results_name = test.replace(exe_directory, '')
        results_name = results_name.replace(".exe", '')
        xml_testsuite = ET.SubElement(xml_root, "testsuite", attrib={"id": results_name})
        
        num_pass = 0
        num_fail = 0
        num_skip = 0
        num_err  = 0
        for line in output.stdout.splitlines():
            # print("Line: " + line)
            try:
                test_case = line.split(":")
                if len(test_case) > 4: # the test has a message attached, possibly because it failed?
                    tested_file = test_case[0]
                    line_num = test_case[1]
                    test_name = test_case[2]
                    result = test_case[3]
                    message = ":".join(test_case[4:]).strip()
                else:
                    tested_file, line_num, test_name, result = test_case
                    message = None
            except ValueError:
                continue
            xml_testcase = ET.SubElement(xml_testsuite, "testcase", attrib={"name": test_name})
            if result != "PASS":
                if result == "IGNORE":
                    ET.SubElement(xml_testcase, "skipped")
                    num_skip += 1
                elif result == "FAIL":
                    ET.SubElement(xml_testcase, "failure", attrib={"message": message})
                    num_fail += 1
                else: # last option is error right?
                    num_err += 1
                    ET.SubElement(xml_testcase, "error", attrib={"message": message})
            else:
                num_pass += 1

        xml_testsuite.set("tests", str(num_err + num_fail + num_pass + num_skip))
        xml_testsuite.set("disabled", str(num_skip))
        xml_testsuite.set("errors", str(num_err))
        xml_testsuite.set("failures", str(num_fail))
    
    tree = ET.ElementTree(xml_root)
    tree.write("results.xml", xml_declaration=True, encoding="UTF-8")