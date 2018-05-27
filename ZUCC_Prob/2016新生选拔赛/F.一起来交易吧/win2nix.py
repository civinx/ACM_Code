import sys

def fixed(path_input, path_output):
    file_input = open(path_input, 'rb')
    all_text = None
    try:
        all_text = file_input.read()
    except:
        print("read %s failed!" % path)
        return
    finally:
        file_input.close()

    all_text = all_text.replace(b'\r\n', b'\n')

    file_output = open(path_output, 'wb')
    file_output.write(all_text)
    file_output.close()

if __name__ == "__main__":
    if len(sys.argv) == 3:
        fixed(sys.argv[1], sys.argv[2])
    elif len(sys.argv) == 2:
        fixed(sys.argv[1], sys.argv[1])
    else:
        print("need more argument")
