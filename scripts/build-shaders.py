import os
import subprocess
import glob

def compile_shaders(shader_dir):
    if not os.path.exists(shader_dir):
        print(f"Error: Directory {shader_dir} does not exist.")
        return
    
    glslc_path = "glslc"
    
    patterns = ["*.vert", "*.frag"]
    
    for pattern in patterns:
        shader_files = glob.glob(os.path.join(shader_dir, pattern))
        if not shader_files:
            print(f"No files matching the pattern {pattern} in {shader_dir}")
            continue
        
        for shader in shader_files:
            spv_file = shader + ".spv"
            cmd = [glslc_path, shader, "-o", spv_file]
            try:
                subprocess.run(cmd, check=True)
                print(f"Compiled: {shader} -> {spv_file}")
            except subprocess.CalledProcessError as e:
                print(f"Compilation error {shader}: {e}")

if __name__ == "__main__":
    shader_directory = "../assets/shaders"
    compile_shaders(shader_directory)