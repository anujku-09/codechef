            </label>

            <label>
                Department
                <input
                    name="department"
                    value={editForm.department}
                    onChange={handleEditChange}
                    required
                />
            </label>

            <label>
                CGPA
                <input
                    type="number"
                    name="cgpa"
                    value={editForm.cgpa}
                    onChange={handleEditChange}
                    min="0"
                    max="10"
                    step="0.1"
                    required
                />
            </label>

            <label>
                Year
                <input
                    type="number"
                    name="year"
                    value={editForm.year}
                    onChange={handleEditChange}
                    min="1"
                    required
                />
            </label>

            <button type="submit">Save Changes</button>

            <button
                type="button"
                onClick={() => setEditingStudent(null)}
            >
                Cancel
            </button>
        </form>
    </div>
)}

        {status === "loading" && (
          <div className="loading-state" role="status">
            Opening the register…
          </div>
        )}