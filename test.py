import GenshinCard
from PIL import Image
from io import BytesIO
character = ["yae"]
data = open("data.json", "r", encoding="utf-8").read()
image_bytes = GenshinCard.get_character(data, character)
print(len(image_bytes))
i = 0
for image in image_bytes:
    bytes_io = BytesIO(image)
    img = Image.open(bytes_io)
    img_name = character[i]
    img.save(f"{img_name}.png")
    i += 1