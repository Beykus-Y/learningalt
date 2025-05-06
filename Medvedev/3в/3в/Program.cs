using OpenTK.Graphics.OpenGL4;
using OpenTK.Mathematics;
using OpenTK.Windowing.Common;
using OpenTK.Windowing.Desktop;
using OpenTK.Windowing.GraphicsLibraryFramework;
using System;

public class GameEngine
{
    private int _cubeVao, _floorVao, _waterVao;
    private int _cubeVbo, _floorVbo, _waterVbo;
    private int _cubeEbo, _floorEbo, _waterEbo;
    private int _shaderProgram;

    private Vector3 cameraPosition = new Vector3(0, 1.5f, 5);
    private Vector3 cameraFront = new Vector3(0, 0, -1);
    private Vector3 cameraUp = Vector3.UnitY;
    private float yaw = -90f;
    private float pitch = 0f;
    private float cameraSpeed = 2.5f;
    private float verticalVelocity = 0f;
    private float gravity = -9.81f;
    private bool isGrounded = true;
    private float jumpStrength = 5f;
    private bool firstMouse = true;
    private Vector2 lastMousePos;

    private Vector3 lightPos = new Vector3(0, 5, 0);
    private float lightAngle = 0f;
    private float waterFlowTime = 0f; // Для анимации воды

    private readonly float[] cubeVertices = {
        -1f, -1f,  1f,   0f,  0f,  1f,
         1f, -1f,  1f,   0f,  0f,  1f,
         1f,  1f,  1f,   0f,  0f,  1f,
        -1f,  1f,  1f,   0f,  0f,  1f,
        -1f, -1f, -1f,   0f,  0f, -1f,
         1f, -1f, -1f,   0f,  0f, -1f,
         1f,  1f, -1f,   0f,  0f, -1f,
        -1f,  1f, -1f,   0f,  0f, -1f,
        -1f, -1f, -1f,  -1f,  0f,  0f,
        -1f, -1f,  1f,  -1f,  0f,  0f,
        -1f,  1f,  1f,  -1f,  0f,  0f,
        -1f,  1f, -1f,  -1f,  0f,  0f,
         1f, -1f, -1f,   1f,  0f,  0f,
         1f, -1f,  1f,   1f,  0f,  0f,
         1f,  1f,  1f,   1f,  0f,  0f,
         1f,  1f, -1f,   1f,  0f,  0f,
        -1f,  1f, -1f,   0f,  1f,  0f,
         1f,  1f, -1f,   0f,  1f,  0f,
         1f,  1f,  1f,   0f,  1f,  0f,
        -1f,  1f,  1f,   0f,  1f,  0f,
        -1f, -1f, -1f,   0f, -1f,  0f,
         1f, -1f, -1f,   0f, -1f,  0f,
         1f, -1f,  1f,   0f, -1f,  0f,
        -1f, -1f,  1f,   0f, -1f,  0f
    };

    private readonly uint[] cubeIndices = {
        0, 1, 2,  2, 3, 0,
        4, 5, 6,  6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };

    private readonly float[] floorVertices = {
        -5f, 0f, -5f,   0f, 1f, 0f,
         5f, 0f, -5f,   0f, 1f, 0f,
         5f, 0f,  5f,   0f, 1f, 0f,
        -5f, 0f,  5f,   0f, 1f, 0f
    };

    private readonly uint[] floorIndices = {
        0, 1, 2,  2, 3, 0
    };

    // Вершины воды (тонкий слой вокруг куба, только передняя грань для примера)
    private readonly float[] waterVertices = {
        -1.1f, -1f,  1.1f,   0f,  0f,  1f,
         1.1f, -1f,  1.1f,   0f,  0f,  1f,
         1.1f,  1f,  1.1f,   0f,  0f,  1f,
        -1.1f,  1f,  1.1f,   0f,  0f,  1f
    };

    private readonly uint[] waterIndices = {
        0, 1, 2,  2, 3, 0
    };

    private double frameTimeAccumulator = 0;
    private int frameCount = 0;
    private GameWindow _window;

    public GameEngine(GameWindow window)
    {
        _window = window;
    }

    public void Initialize()
    {
        GL.Enable(EnableCap.DepthTest);
        GL.Enable(EnableCap.Blend); // Для прозрачности воды
        GL.BlendFunc(BlendingFactor.SrcAlpha, BlendingFactor.OneMinusSrcAlpha);

        // Куб
        _cubeVao = GL.GenVertexArray();
        GL.BindVertexArray(_cubeVao);
        _cubeVbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ArrayBuffer, _cubeVbo);
        GL.BufferData(BufferTarget.ArrayBuffer, cubeVertices.Length * sizeof(float), cubeVertices, BufferUsageHint.StaticDraw);
        _cubeEbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ElementArrayBuffer, _cubeEbo);
        GL.BufferData(BufferTarget.ElementArrayBuffer, cubeIndices.Length * sizeof(uint), cubeIndices, BufferUsageHint.StaticDraw);
        GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 0);
        GL.EnableVertexAttribArray(0);
        GL.VertexAttribPointer(1, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 3 * sizeof(float));
        GL.EnableVertexAttribArray(1);

        // Пол
        _floorVao = GL.GenVertexArray();
        GL.BindVertexArray(_floorVao);
        _floorVbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ArrayBuffer, _floorVbo);
        GL.BufferData(BufferTarget.ArrayBuffer, floorVertices.Length * sizeof(float), floorVertices, BufferUsageHint.StaticDraw);
        _floorEbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ElementArrayBuffer, _floorEbo);
        GL.BufferData(BufferTarget.ElementArrayBuffer, floorIndices.Length * sizeof(uint), floorIndices, BufferUsageHint.StaticDraw);
        GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 0);
        GL.EnableVertexAttribArray(0);
        GL.VertexAttribPointer(1, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 3 * sizeof(float));
        GL.EnableVertexAttribArray(1);

        // Вода
        _waterVao = GL.GenVertexArray();
        GL.BindVertexArray(_waterVao);
        _waterVbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ArrayBuffer, _waterVbo);
        GL.BufferData(BufferTarget.ArrayBuffer, waterVertices.Length * sizeof(float), waterVertices, BufferUsageHint.StaticDraw);
        _waterEbo = GL.GenBuffer();
        GL.BindBuffer(BufferTarget.ElementArrayBuffer, _waterEbo);
        GL.BufferData(BufferTarget.ElementArrayBuffer, waterIndices.Length * sizeof(uint), waterIndices, BufferUsageHint.StaticDraw);
        GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 0);
        GL.EnableVertexAttribArray(0);
        GL.VertexAttribPointer(1, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 3 * sizeof(float));
        GL.EnableVertexAttribArray(1);

        // Шейдеры
        string vertexShaderSource = @"
            #version 330 core
            layout(location = 0) in vec3 aPosition;
            layout(location = 1) in vec3 aNormal;

            uniform mat4 model;
            uniform mat4 view;
            uniform mat4 projection;
            uniform float time; // Для анимации воды

            out vec3 Normal;
            out vec3 FragPos;
            out float WaterFlow;

            void main()
            {
                vec3 pos = aPosition;
                if (aNormal.z > 0.9) { // Только для передней грани воды
                    pos.y -= mod(time, 2.0); // Простая анимация падения
                }
                gl_Position = projection * view * model * vec4(pos, 1.0);
                FragPos = vec3(model * vec4(aPosition, 1.0));
                Normal = normalize(mat3(transpose(inverse(model))) * aNormal);
                WaterFlow = pos.y;
            }";

        string fragmentShaderSource = @"
            #version 330 core
            out vec4 FragColor;

            in vec3 Normal;
            in vec3 FragPos;
            in float WaterFlow;

            uniform vec3 lightPos;
            uniform vec3 viewPos;
            uniform vec3 objectColor;
            uniform vec3 lightColor;
            uniform float time;

            void main()
            {
                vec3 norm = normalize(Normal);
                vec3 lightDir = normalize(lightPos - FragPos);

                // Ambient
                float ambientStrength = 0.3;
                vec3 ambient = ambientStrength * lightColor;

                // Diffuse
                float diff = max(dot(norm, lightDir), 0.0);
                vec3 diffuse = diff * lightColor;

                // Specular
                float specularStrength = 0.7;
                vec3 viewDir = normalize(viewPos - FragPos);
                vec3 reflectDir = reflect(-lightDir, norm);
                float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
                vec3 specular = specularStrength * spec * lightColor;

                vec3 result = (ambient + diffuse + specular) * objectColor;

                // Эффект воды
                if (norm.z > 0.9) { // Только для передней грани воды
                    float alpha = 0.5 + 0.3 * sin(WaterFlow * 3.0 + time); // Пульсация прозрачности
                    FragColor = vec4(0.0, 0.5, 1.0, alpha); // Голубая вода с прозрачностью
                } else {
                    FragColor = vec4(result, 1.0);
                }
            }";

        int vertexShader = GL.CreateShader(ShaderType.VertexShader);
        GL.ShaderSource(vertexShader, vertexShaderSource);
        GL.CompileShader(vertexShader);

        int fragmentShader = GL.CreateShader(ShaderType.FragmentShader);
        GL.ShaderSource(fragmentShader, fragmentShaderSource);
        GL.CompileShader(fragmentShader);

        _shaderProgram = GL.CreateProgram();
        GL.AttachShader(_shaderProgram, vertexShader);
        GL.AttachShader(_shaderProgram, fragmentShader);
        GL.LinkProgram(_shaderProgram);

        GL.DeleteShader(vertexShader);
        GL.DeleteShader(fragmentShader);
    }

    public void Update(double deltaTime)
    {
        var keyboard = _window.KeyboardState;

        float moveSpeed = cameraSpeed * (float)deltaTime;
        Vector3 moveDirection = Vector3.Zero;
        if (keyboard.IsKeyDown(Keys.W)) moveDirection += cameraFront;
        if (keyboard.IsKeyDown(Keys.S)) moveDirection -= cameraFront;
        if (keyboard.IsKeyDown(Keys.A)) moveDirection -= Vector3.Normalize(Vector3.Cross(cameraFront, cameraUp));
        if (keyboard.IsKeyDown(Keys.D)) moveDirection += Vector3.Normalize(Vector3.Cross(cameraFront, cameraUp));

        if (moveDirection != Vector3.Zero)
        {
            moveDirection.Y = 0;
            cameraPosition += Vector3.Normalize(moveDirection) * moveSpeed;
        }

        if (keyboard.IsKeyDown(Keys.Space) && isGrounded)
        {
            verticalVelocity = jumpStrength;
            isGrounded = false;
        }

        verticalVelocity += gravity * (float)deltaTime;
        cameraPosition.Y += verticalVelocity * (float)deltaTime;

        if (cameraPosition.Y <= 1.5f)
        {
            cameraPosition.Y = 1.5f;
            verticalVelocity = 0;
            isGrounded = true;
        }

        if (keyboard.IsKeyDown(Keys.Escape)) _window.Close();

        frameTimeAccumulator += deltaTime;
        frameCount++;
        if (frameTimeAccumulator >= 1.0)
        {
            _window.Title = $"FPS: {frameCount}";
            frameCount = 0;
            frameTimeAccumulator -= 1.0;
        }

        lightAngle += (float)deltaTime;
        lightPos.X = (float)Math.Cos(lightAngle) * 5;
        lightPos.Z = (float)Math.Sin(lightAngle) * 5;

        waterFlowTime += (float)deltaTime; // Обновление времени для анимации воды
    }

    public void OnMouseMove(MouseMoveEventArgs e)
    {
        if (firstMouse)
        {
            lastMousePos = new Vector2(e.X, e.Y);
            firstMouse = false;
            return;
        }

        float sensitivity = 0.1f;
        float xOffset = (e.X - lastMousePos.X) * sensitivity;
        float yOffset = (lastMousePos.Y - e.Y) * sensitivity;

        lastMousePos = new Vector2(e.X, e.Y);

        yaw += xOffset;
        pitch += yOffset;

        pitch = MathHelper.Clamp(pitch, -89f, 89f);

        Vector3 direction;
        direction.X = (float)Math.Cos(MathHelper.DegreesToRadians(yaw)) * (float)Math.Cos(MathHelper.DegreesToRadians(pitch));
        direction.Y = (float)Math.Sin(MathHelper.DegreesToRadians(pitch));
        direction.Z = (float)Math.Sin(MathHelper.DegreesToRadians(yaw)) * (float)Math.Cos(MathHelper.DegreesToRadians(pitch));
        cameraFront = Vector3.Normalize(direction);
    }

    public void Render(double deltaTime)
    {
        GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

        GL.UseProgram(_shaderProgram);

        float aspectRatio = (float)_window.ClientSize.X / _window.ClientSize.Y;
        Matrix4 view = Matrix4.LookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
        Matrix4 projection = Matrix4.CreatePerspectiveFieldOfView(MathHelper.DegreesToRadians(45.0f), aspectRatio, 0.1f, 100.0f);

        GL.UniformMatrix4(GL.GetUniformLocation(_shaderProgram, "view"), false, ref view);
        GL.UniformMatrix4(GL.GetUniformLocation(_shaderProgram, "projection"), false, ref projection);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "lightPos"), lightPos);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "viewPos"), cameraPosition);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "lightColor"), new Vector3(1.0f, 1.0f, 1.0f));
        GL.Uniform1(GL.GetUniformLocation(_shaderProgram, "time"), waterFlowTime);

        // Куб
        Matrix4 cubeModel = Matrix4.CreateTranslation(0, 1, 0);
        GL.UniformMatrix4(GL.GetUniformLocation(_shaderProgram, "model"), false, ref cubeModel);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "objectColor"), new Vector3(0.8f, 0.8f, 0.8f));
        GL.BindVertexArray(_cubeVao);
        GL.DrawElements(PrimitiveType.Triangles, cubeIndices.Length, DrawElementsType.UnsignedInt, 0);

        // Пол
        Matrix4 floorModel = Matrix4.Identity;
        GL.UniformMatrix4(GL.GetUniformLocation(_shaderProgram, "model"), false, ref floorModel);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "objectColor"), new Vector3(0.3f, 0.5f, 0.3f));
        GL.BindVertexArray(_floorVao);
        GL.DrawElements(PrimitiveType.Triangles, floorIndices.Length, DrawElementsType.UnsignedInt, 0);

        // Вода
        Matrix4 waterModel = Matrix4.CreateTranslation(0, 1, 0); // Вода на уровне куба
        GL.UniformMatrix4(GL.GetUniformLocation(_shaderProgram, "model"), false, ref waterModel);
        GL.Uniform3(GL.GetUniformLocation(_shaderProgram, "objectColor"), new Vector3(0.0f, 0.5f, 1.0f)); // Цвет воды
        GL.BindVertexArray(_waterVao);
        GL.DrawElements(PrimitiveType.Triangles, waterIndices.Length, DrawElementsType.UnsignedInt, 0);
    }

    public void Cleanup()
    {
        GL.DeleteBuffer(_cubeVbo);
        GL.DeleteBuffer(_cubeEbo);
        GL.DeleteVertexArray(_cubeVao);
        GL.DeleteBuffer(_floorVbo);
        GL.DeleteBuffer(_floorEbo);
        GL.DeleteVertexArray(_floorVao);
        GL.DeleteBuffer(_waterVbo);
        GL.DeleteBuffer(_waterEbo);
        GL.DeleteVertexArray(_waterVao);
        GL.DeleteProgram(_shaderProgram);
    }
}

class Program
{
    static void Main(string[] args)
    {
        var settings = new NativeWindowSettings
        {
            ClientSize = new Vector2i(800, 600),
            APIVersion = new Version(4, 0)
        };

        using (var window = new GameWindow(GameWindowSettings.Default, settings))
        {
            window.CursorState = CursorState.Grabbed;
            GameEngine engine = new GameEngine(window);

            window.Load += engine.Initialize;
            window.UpdateFrame += (e) => engine.Update(e.Time);
            window.MouseMove += (e) => engine.OnMouseMove(e);
            window.RenderFrame += (e) =>
            {
                engine.Render(e.Time);
                window.SwapBuffers();
            };
            window.Unload += engine.Cleanup;

            window.Run();
        }
    }
}