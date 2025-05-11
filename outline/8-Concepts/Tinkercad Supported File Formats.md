### ✅ **Tinkercad Supported File Formats**

Tinkercad supports a streamlined set of file formats focused on accessibility and compatibility with 3D printing and electronics design.



#### 🧱 **For 3D Modeling:**

| Format         | Extension       | Purpose                                        | Notes                                                             |
| -------------- | --------------- | ---------------------------------------------- | ----------------------------------------------------------------- |
| **STL**        | `.stl`          | Export/import 3D geometry                      | Most common for 3D printing                                       |
| **OBJ**        | `.obj`          | Export/import geometry with color              | Tinkercad accepts `.obj` but **does not support `.mtl` textures** |
| **GLTF / GLB** | `.gltf`, `.glb` | Export only (for use in AR/VR or 3D viewers)   | GLB is the binary version of glTF                                 |
| **SVG**        | `.svg`          | Import 2D vector shapes into the **Workplane** | Used for laser cutting or extruding into 3D                       |
| **STEP**       | `.step`, `.stp` | ❌ *Not supported directly*                     | Requires conversion before importing                              |

#### 🧰 **For Circuit Design (Tinkercad Circuits):**

* **Code Files:** You can write code in **C/C++** (for Arduino) and **block-based** environments (like Scratch).
* **Component Libraries:** Built into the editor, not uploaded via files.

#### 📤 **Export Options:**

* STL (for 3D printing)
* OBJ
* GLB (for use in AR/VR)
* SVG (2D outlines)
* Tinkercad native `.123dx` is no longer commonly used (legacy Autodesk format)

---

### 🔄 Need to Import a Format Not Supported?

Use **conversion tools** like:

* **FreeCAD** → Convert STEP to STL or OBJ
* **Blender** → For OBJ, GLTF, FBX conversions
* **MeshLab** → Clean or repair meshes before STL export

---
