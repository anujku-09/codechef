            body: JSON.stringify(formData)
        });

        if (!res.ok) {
            throw new Error("Failed to add student");
        }

        const student = await res.json();

        setStudents((prev) =>
            [...prev, student].sort((a, b) =>
                a.name.localeCompare(b.name)
            )
        );

        setFormData({ ...emptyForm });
        setErrorMessage("");
        setStatus("loaded");
    } catch (err) {
        setErrorMessage(err.message);
        setStatus("error");
    }
}

async function handleDelete(id) {
    try {
        const res = await fetch(`${API_URL}/${id}`, {
            method: "DELETE"
        });

        if (!res.ok) {
            throw new Error("Failed to delete student");
        }

        await res.json();

        setStudents((prev) =>
            prev.filter((student) => student._id !== id)