from PIL import Image
import glob, os


for infile in glob.glob("*.gif"):
    file, ext = os.path.splitext(infile)
    with Image.open(infile) as im:
        im = im.convert('RGB')
        # print(im.format)
        # im.show()
        im.save(file + ".pgm", format="PPM")